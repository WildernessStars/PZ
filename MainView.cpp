//
// Created by sun on 8/25/16.
//

#include "MainView.h"
#include "menu.h"
#include "GameScene.h"

MainView *gMainView;

MainView::MainView():menuScene(nullptr), gameScene(nullptr){
	gMainView = this;
	setMouseTracking(true);
	
	//setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setMinimumSize(900, 600);
	horizontalScrollBar()->setStyleSheet("QScrollBar:horizontal"
		"{"
		"height:4px;"
		"background:#FFFFFF;"
		"margin:0px,0px,0px,0px;"
		"padding-top:0px;"
		"padding-bottom:0px;"
		"padding-left:2px;"
		"padding-right:2px;"
		"}"
		"QScrollBar::handle:horizontal"
		"{"
		"height:4px;"
		"background:#dbdbdb;"
		"border-radius:0px;"
		"min-width:0px;"
		"}"
	);
}

MainView::~MainView(){
	if (menuScene)
		menuScene->deleteLater();
	if (gameScene)
		gameScene->deleteLater();
}


void MainView::switchToGameScene()
{
	GameScene *newGameScene = new GameScene();
	setScene(newGameScene);
	if (gameScene)
		gameScene->deleteLater();
	gameScene = newGameScene;
	gameScene->loadReady();

	//connect(gameScene, &GameScene::mousePress, [this] {
	//	QTimer *timer = new QTimer(this);
	//	timer->start(1000);
	//	horizontalScrollBar()->setSliderPosition(300);
	//});
}

void MainView::switchToMenuScene()
{
	MenuScene *newmenu = new MenuScene;
	setScene(newmenu);
	if (newmenu)
		menuScene->deleteLater();
	menuScene = newmenu;
}


MainWindow::MainWindow(): mainView(new MainView()){
	resize(900, 600);
	QWidget *centralWidget = new QWidget;
	mainView->setGeometry(0,0,900,600);
	QHBoxLayout *horizonlayout = new QHBoxLayout();
	horizonlayout->setGeometry(QRect(0, 0, 900, 600));	
	horizonlayout->addWidget(mainView);
	horizonlayout->setContentsMargins(0, 0, 0, 0);
	centralWidget->setLayout(horizonlayout);
	setCentralWidget(centralWidget);
}
