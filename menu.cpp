//
// Created by sun on 8/25/16.
//

#include "menu.h"
#include "MainView.h"
#include "loadImager.h"
#include "GifItem.h"
GifItem::GifItem(const QString & path, QGraphicsItem * parent){
	QLabel* aniLabel = new QLabel();
	gifitem = new QMovie(path);
	QGraphicsProxyWidget* aniWidget = new QGraphicsProxyWidget(this);
	aniLabel->setAttribute(Qt::WA_NoSystemBackground);
	aniLabel->setMovie(gifitem);
	aniWidget->setWidget(aniLabel);
	aniWidget->setPos(0,0);
	aniLabel->show();
	gifitem->start();
	if(path[17]=='S')
		connect(gifitem,&QMovie::finished, [this] { emit finished(); });
	if(path.contains("Die")||path.contains("Head")|| path.contains("shAttack"))
		connect(gifitem, &QMovie::finished, [this] { delete this; });

}
void GifItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget){

}

QRectF GifItem::boundingRect() const{
	return QRectF(-400,-400,800,800);
}






MenuScene::MenuScene(): QGraphicsScene(0, 0, 900, 600),
	Dave(new GifItem("images/interface/Dave3.gif")),
	background(new QGraphicsPixmapItem(gImageCache->load("interface/SelectorBackground.png"))),
	adventureButton(new  MyPixItem(gImageCache->load("interface/SelectorAdventureButton.png"))){
	addItem(background);
	Dave->setPos(0, 0); addItem(Dave);
	adventureButton->setPos(474, 80);  addItem(adventureButton);
	
	connect(adventureButton, &MyPixItem::clicked, [this] {
		adventureButton->setCursor(Qt::ArrowCursor);
		adventureButton->setEnabled(false);
		GifItem *zombieHand=new GifItem("images/interface/SelectorZombieHand.gif");
		zombieHand->setPos(270, 260);
		addItem(zombieHand);
		connect(zombieHand, &GifItem::finished, [this,zombieHand] {
			delete zombieHand;
			gMainView->switchToGameScene();
		});
	});
	
	
}


