//
// Created by sun on 8/26/16.
//
#pragma comment(lib,"winmm.lib")

#include <stdlib.h>
#include <math.h>
#include "GameScene.h"
#include "MainView.h"
#include "loadImager.h"
#include "Plant.h"
#include "Zombie.h"
#include "Store.h"
#include "PlantCard.h"
#include "GifItem.h"
#include "QDebug"
#include<random>  
#include<time.h>  

DWORD t1, t2, t3, t4, t5, t6;

#define MAX_ATN 300
GameScene::~GameScene(){
	delete shovel;
	delete background;
		delete backmenu;
		delete shovelBack;
		delete SunBack;
		delete SumSun;
		delete timer1;
		delete timer2;
		delete timer3;
		delete timer4;
		delete timer6;
		delete timer5;
		delete p;
}
void GameScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent){
	QGraphicsScene::mouseMoveEvent(mouseEvent);
	if (cardselected.SelectedCard!=nullptr) {
		cardselected.SelectedCard->setPos(mouseEvent->scenePos());
	}
	emit mouseMove(mouseEvent);
}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent){
	QGraphicsScene::mousePressEvent(mouseEvent);
	emit mousePress(mouseEvent);
}

void GameScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) {
	QGraphicsScene::mouseReleaseEvent(mouseEvent);
	if (cardselected.SelectedCard != nullptr) {
		delete cardselected.SelectedCard;
		cardselected.SelectedCard = nullptr;
		if(mouseEvent->scenePos().x()>80&& mouseEvent->scenePos().x()<800&& mouseEvent->scenePos().y()>70&& mouseEvent->scenePos().y()<550){
			
			int a = ((int)mouseEvent->scenePos().x() - 120) / 80;
			int b = ((int)mouseEvent->scenePos().y() - 75) / 100;
			settingpos=QPointF(120+a * 80 + 5, 75+b * 100 + 5);
			
			switch (cardselected.kind) {
			case 1:p = new Pea_Shooter(1); mystore.getPea_1(); break;
			case 2:p = new Sunflower; mystore.getSun(); break;
			case 3:p = new Ice_Shooter; mystore.getIce(); break;
			case 4:p = new High_Nut; mystore.getHNut(); settingpos = QPointF(120 + a * 80 + 5, 75 + b * 100 - 45); break;
			case 5:p = new Ground_Thorn; mystore.getGround(); settingpos = QPointF(120 + a * 80 + 5, 75 + b * 100 + 10); break;
			case 6:p = new Potato_Mine; mystore.getPotato(); break;
			case 7:p = new Cherry_Bomb; mystore.getCherry(); break;
			case 8:p = new Hot_Pepper; mystore.getPepper(); break;
			case 9:p = new Squash; mystore.getSquash(); settingpos = QPointF(120 + a * 80 -15, 75 + b * 100 -160); break;
			default:
				break;
			}
			if (yard[b][a].map[0] == NULL || yard[b][a].map[0]->pztype == 0) {
				yard[b][a].map[0] = p;
				yard[b][a].num = 1;
				yard[b][a].map[0]->pztype = 1;
				mystore.cd[cardselected.kind - 1] = mystore.CD[cardselected.kind - 1];
				sum_sunshine -= mystore.price[cardselected.kind - 1];
				emit mouseRelease(mouseEvent);
			}
		}
	}
	if (shovel->isSelected()) {
		int a = ((int)mouseEvent->scenePos().x() - 120) / 80;
		int b = ((int)mouseEvent->scenePos().y() - 75) / 100;
		qDebug() << a << b;
		shovel->setPos(0, 0);
		shovel->setSelected(false);
		if (yard[b][a].map[0] != NULL && yard[b][a].map[0]->pztype == 1) {
			removeItem(yard[b][a].map[0]->getitem());
			delete[]yard[b][a].map[0];
			yard[b][a].map[0] = NULL;
		
			yard[b][a].num = 0;
			//yard[b][a].map[0]->pztype = 0;
		}
	}
}

void GameScene::loadReady(){
	background->setPos(-115, 0);	
}

GameScene::GameScene(): QGraphicsScene(0, 0, 900, 600),
	background(new myPixmap(gImageCache->load("interface/background1.jpg"))),
	backmenu(new MyPixItem(gImageCache->load("interface/Button.png"))),
	shovel(new QGraphicsPixmapItem(gImageCache->load("interface/Shovel.png"))),
	shovelBack(new QGraphicsPixmapItem(gImageCache->load("interface/ShovelBack.png"))),
	SunBack(new QGraphicsPixmapItem(gImageCache->load("interface/SunBack.png"))),
	p(nullptr),SumSun(new QGraphicsTextItem(tr("  "))){
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++)
				yard[i][j].map[k] = NULL;
			yard[i][j].num = 0;
			yard[i][j].HP = 0;
			yard[i][j].ground = false;
		}
	}
	islose = false;
	sumPoint = 50;
	cardselected.SelectedCard = nullptr;
	addItem(background);
	QPropertyAnimation *animation=new QPropertyAnimation(background, "pos");
	animation->setDuration(1000);
	animation->setStartValue(QPoint(0, 0));
	animation->setEndValue(QPoint(-500, 0));
	animation->setEasingCurve(QEasingCurve::OutCubic);
	connect(animation, &QPropertyAnimation::finished,this, [=] {
		//要处理的函数
		normal_Zombies *zom1 = new normal_Zombies();
		zom1->item->setPos(600, 100);	addItem(zom1->item);
		normal_Zombies *zom2 = new normal_Zombies();
		zom2->item->setPos(610, 150);	addItem(zom2->item);
		normal_Zombies *zom3 = new normal_Zombies();
		zom3->item->setPos(620, 200);	addItem(zom3->item);
		normal_Zombies *zom4 = new normal_Zombies();
		zom4->item->setPos(630, 250);	addItem(zom4->item);
		normal_Zombies *zom5 = new normal_Zombies();
		zom5->item->setPos(640, 300);	addItem(zom5->item);
		roadblock_Zombies *zom6 = new roadblock_Zombies();
		zom6->item->setPos(650, 150); addItem(zom6->item);
		roadblock_Zombies *zom7 = new roadblock_Zombies();
		zom7->item->setPos(660, 200); addItem(zom7->item);
		newspaper_Zombies *zom8 = new newspaper_Zombies();
		zom8->item->setPos(680, 250); addItem(zom8->item);
		QTimer::singleShot(1900, [=]() {
			delete zom1; delete zom2; delete zom3; delete zom4; delete zom5; delete zom6; delete zom7;delete zom8;
		});
	});
	animation->start(QAbstractAnimation::DeleteWhenStopped);
	QTimer::singleShot(3000, [=]() { 
		QPropertyAnimation *animation2 = new QPropertyAnimation(background, "pos");
		animation2->setDuration(1000);
		animation2->setStartValue(QPoint(-500, 0));
		animation2->setEndValue(QPoint(-140, 0));
		animation2->setEasingCurve(QEasingCurve::OutCubic);
		connect(animation2, &QPropertyAnimation::finished, this, [=] {
			//放卡片，太阳板，铲子	
			
			
			shovel->setParentItem(shovelBack);
			shovelBack->setHandlesChildEvents(false);
			shovel->setFlags(QGraphicsItem::ItemIsMovable| QGraphicsItem::ItemIsSelectable);
			shovelBack->setPos(240, 2);
			shovel->setPos(0, 0);
			//shovelBackground->setZValue(1);
			addItem(shovelBack);
			
			string ttmp = to_string(sum_sunshine);
			SumSun = new QGraphicsTextItem(tr(ttmp.c_str()));
			SumSun->setPos(160, 10);
			SunBack->setPos(100, 3);
			addItem(SunBack);
			addItem(SumSun);
			
			CardGraphicsItem card1;
			card1.plantCard = new PlantCardItem(gImageCache->load("/Card/Plants/Peashooter.png"));
			card1.plantCard->setPos(0, 0);	addItem(card1.plantCard);
			card1.plantAvalible = new PlantCardAvalible(1, 5, gImageCache->load("/Card/Plants/Peashooter.png"));
			card1.plantAvalible->setPos(0, 0);	addItem(card1.plantAvalible);
			cardGraphics.append(card1);
			CardGraphicsItem card2;
			card2.plantCard = new PlantCardItem(gImageCache->load("/Card/Plants/SunFlower.png"));
			card2.plantCard->setPos(0, 60);	addItem(card2.plantCard);
			card2.plantAvalible = new PlantCardAvalible(2, 5, gImageCache->load("/Card/Plants/SunFlower.png"));
			card2.plantAvalible->setPos(0, 60);	addItem(card2.plantAvalible);
			cardGraphics.append(card2);
			CardGraphicsItem card3;
			card3.plantCard = new PlantCardItem(gImageCache->load("/Card/Plants/SnowPea.png"));
			card3.plantCard->setPos(0, 120);	addItem(card3.plantCard);
			card3.plantAvalible = new PlantCardAvalible(3, 5, gImageCache->load("/Card/Plants/SnowPea.png"));
			card3.plantAvalible->setPos(0, 120);	addItem(card3.plantAvalible);
			cardGraphics.append(card3);
			CardGraphicsItem card4;
			card4.plantCard = new PlantCardItem(gImageCache->load("/Card/Plants/TallNut.png"));
			card4.plantCard->setPos(0, 180);	addItem(card4.plantCard);
			card4.plantAvalible = new PlantCardAvalible(4, 5, gImageCache->load("/Card/Plants/TallNut.png"));
			card4.plantAvalible->setPos(0, 180);	addItem(card4.plantAvalible);
			cardGraphics.append(card4);
			CardGraphicsItem card5;
			card5.plantCard = new PlantCardItem(gImageCache->load("/Card/Plants/Spikeweed.png"));
			card5.plantCard->setPos(0, 240);	addItem(card5.plantCard);
			card5.plantAvalible = new PlantCardAvalible(5, 5, gImageCache->load("/Card/Plants/Spikeweed.png"));
			card5.plantAvalible->setPos(0, 240);	addItem(card5.plantAvalible);
			cardGraphics.append(card5);
			CardGraphicsItem card6;
			card6.plantCard = new PlantCardItem(gImageCache->load("/Card/Plants/PotatoMine.png"));
			card6.plantCard->setPos(0, 300);	addItem(card6.plantCard);
			card6.plantAvalible = new PlantCardAvalible(6, 5, gImageCache->load("/Card/Plants/PotatoMine.png"));
			card6.plantAvalible->setPos(0, 300);	addItem(card6.plantAvalible);
			cardGraphics.append(card6);
			CardGraphicsItem card7;
			card7.plantCard = new PlantCardItem(gImageCache->load("/Card/Plants/CherryBomb.png"));
			card7.plantCard->setPos(0, 360);	addItem(card7.plantCard);
			card7.plantAvalible = new PlantCardAvalible(7, 5, gImageCache->load("/Card/Plants/CherryBomb.png"));
			card7.plantAvalible->setPos(0, 360);	addItem(card7.plantAvalible);
			cardGraphics.append(card7);
			CardGraphicsItem card8;
			card8.plantCard = new PlantCardItem(gImageCache->load("/Card/Plants/Jalapeno.png"));
			card8.plantCard->setPos(0, 420);	addItem(card8.plantCard);
			card8.plantAvalible = new PlantCardAvalible(8, 5, gImageCache->load("/Card/Plants/Jalapeno.png"));
			card8.plantAvalible->setPos(0, 420);	addItem(card8.plantAvalible);
			cardGraphics.append(card8);
			CardGraphicsItem card9;
			card9.plantCard = new PlantCardItem(gImageCache->load("/Card/Plants/Squash.png"));
			card9.plantCard->setPos(0, 480);	addItem(card9.plantCard);
			card9.plantAvalible = new PlantCardAvalible(9, 5, gImageCache->load("/Card/Plants/Squash.png"));
			card9.plantAvalible->setPos(0, 480);	addItem(card9.plantAvalible);	
			cardGraphics.append(card9);

			QGraphicsPixmapItem *PrepareGrowPlants = new QGraphicsPixmapItem(gImageCache->load("interface/PrepareGrowPlants.png"));
			PrepareGrowPlants->setPos(350,100);	 addItem(PrepareGrowPlants);
			QTimer::singleShot(1500, [=]() {
				delete PrepareGrowPlants;
			});
		});
		animation2->start(QAbstractAnimation::DeleteWhenStopped);
	});
	t1 = timeGetTime();
	timer1 = new QTimer(this);
	timer2 = new QTimer(this);
	timer3 = new QTimer(this);
	timer4 = new QTimer(this);
	timer5 = new QTimer(this);
	timer6 = new QTimer(this);
	QTimer::singleShot(5000, [=]() {
		for (int k = 0; k < cardGraphics.length(); k++) {
			int kind = cardGraphics[k].plantAvalible->plantkind;
			int pre = cardGraphics[k].plantAvalible->percent;
			connect(cardGraphics[k].plantAvalible, &PlantCardAvalible::clicked, [this,kind,k] {
				if (cardGraphics[k].plantAvalible->percent >= 99&&sum_sunshine>=mystore.price[kind-1]) {
					MyPixItem *p1;
					switch (kind) {
					case 1:p1 = new MyPixItem(gImageCache->load("Plants/Peashooter/0.gif")); p1->setPos(10, 0); break;
					case 2:p1 = new MyPixItem(gImageCache->load("Plants/SunFlower/0.gif"));  p1->setPos(10, 60); break;
					case 3:p1 = new MyPixItem(gImageCache->load("Plants/SnowPea/0.gif"));  p1->setPos(10, 120); break;
					case 4:p1 = new MyPixItem(gImageCache->load("Plants/TallNut/0.gif"));  p1->setPos(10, 180); break;
					case 5:p1 = new MyPixItem(gImageCache->load("Plants/Spikeweed/0.gif")); p1->setPos(10, 240); break;
					case 6:p1 = new MyPixItem(gImageCache->load("Plants/PotatoMine/0.gif"));  p1->setPos(10, 300); break;
					case 7:p1 = new MyPixItem(gImageCache->load("Plants/CherryBomb/0.gif"));  p1->setPos(10, 360); break;
					case 8:p1 = new MyPixItem(gImageCache->load("Plants/Jalapeno/0.gif"));  p1->setPos(10, 420); break;
					case 9:p1 = new MyPixItem(gImageCache->load("Plants/Squash/0.gif"));  p1->setPos(10, 480); break;
					default:
						break;
					}
					addItem(p1);
					cardselected.kind = kind;
					cardselected.SelectedCard = p1;
					p1->setFlag(QGraphicsItem::ItemIsMovable);
					p1->setSelected(true);
					
				}
			});
		}
		connect(this, &GameScene::mouseRelease,[this](QGraphicsSceneMouseEvent *e) {
			if (p != nullptr) {
				p->getitem()->setPos(settingpos);
				addItem(p->getitem());
				
			}
		});//选择植物和放置植物
		
		timer1->start(20000);
		connect(timer1, SIGNAL(timeout()), this, SLOT(produceFirstZombie()));
		
		timer2->start(6000);
		connect(timer2, SIGNAL(timeout()), this, SLOT(produceSunshine()));
		
		timer3->start(2000);
		connect(timer3, SIGNAL(timeout()), this, SLOT(gameattack()));
		
		timer4->start(250);
		connect(timer4, SIGNAL(timeout()), this, SLOT(gamemove()));
	
		timer5->start(1000);
		connect(timer5, SIGNAL(timeout()), this, SLOT(countdown()));

		timer6->start(1000);
		connect(timer6, SIGNAL(timeout()), this, SLOT(peashoo()));
	});

	QGraphicsTextItem *menuText = new QGraphicsTextItem(tr("Menu"));
	menuText->setParentItem(backmenu);
	menuText->setPos(35,10);
	backmenu->setPos(700 ,0);
	addItem(backmenu);
	
}

void GameScene::gameattack() {
	t3 = timeGetTime();
	if (t3-t1 > 21000) {
		Plantsattack();
		Zombiesattack();
	}
	if (islose)
		timer3->stop();
}
void GameScene::gamemove() {

	if (SumSun != nullptr) {
		removeItem(SumSun);
		string ttmp = to_string(sum_sunshine);
		SumSun = new QGraphicsTextItem(tr(ttmp.c_str()));
		SumSun->setPos(160, 10);
		addItem(SumSun);
	}
	t4 = timeGetTime();
	if (t4-t1 > 20000) {;
		moveZombies(t4-t1);
	}
	if (islose)
		timer4->stop();
}

void GameScene::produceFirstZombie() {
	t2 = timeGetTime();
	srand((unsigned)time(NULL));
	int rd = (rand() % 5);
	yard[rd][9].map[0] = new flag_Zombies();
	yard[rd][9].map[0]->setwaittime(t2 - t1);
	yard[rd][9].map[0]->setpos(make_pair(rd, 9));
	yard[rd][9].num = 1;
	yard[rd][9].map[0]->getitem()->setPos(120 + 9 * 80 -20, 75 + rd * 100 -60);
	addItem(yard[rd][9].map[0]->getitem());
	QTimer::singleShot(2000, [=]() {
		produceZombies(); });
	if (islose)
		timer1->stop();
}

void GameScene::produceZombies(){
	int num;
	t5 = timeGetTime();
	long long ms = t5 - t1;
	num = 5;
	default_random_engine random(time(NULL));
	uniform_int_distribution<int> dis1(0, 100);
	for (int i = 0; i < num; i++) {
		int rd = (dis1(random) % 5);
		int temp = yard[rd][9].num;
		if (temp == 5) {
			//i--;
			continue;
		}
		default_random_engine random2(time(NULL));
		uniform_int_distribution<int> dis2(0, 100);
		int rdd = (dis2(random2) % 100);
		int k = selectZombies(ms / 1000, rdd);
		switch (k) {
		case 0:yard[rd][9].map[temp] = new normal_Zombies(); yard[rd][9].map[temp]->setwaittime(ms); break;
		case 1:yard[rd][9].map[temp] = new roadblock_Zombies(); yard[rd][9].map[temp]->setwaittime(ms); break;
		case 3: yard[rd][9].map[temp] = new newspaper_Zombies(); yard[rd][9].map[temp]->setwaittime(ms); break;
		case 4: yard[rd][9].map[temp] = new clown_Zombies(); yard[rd][9].map[temp]->setwaittime(ms); break;
		default: break;
		}
		yard[rd][9].map[temp]->setpos(make_pair(rd, 9));
		yard[rd][9].num++;
	
		yard[rd][9].map[temp]->getitem()->setPos(120 + 9 * 80 -20, 75 + rd * 100 -60);
		addItem(yard[rd][9].map[temp]->getitem());
		//Sleep(200);
	}
}

void GameScene::countdown(){
	t5 = timeGetTime();
	if (t5 - t1 > 3000) {
		mystore.countdown();
		for (int i = 0; i < cardGraphics.length(); i++) {
			bool afford = false;
			if (sum_sunshine >= mystore.price[i])
				afford = true;
			cardGraphics[i].plantAvalible->UpdateCard(((mystore.CD[i]-mystore.cd[i]) * 100) / mystore.CD[i],afford);
		}
	}
	if (islose)
		timer5->stop();
}

void GameScene::produceSunshine(){
	SunShine*ssh[20];
	for (int i = 0; i < 20; i++)
		ssh[i] = NULL;
	int shineindex = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (yard[i][j].map[0] != NULL && strcmp(yard[i][j].map[0]->getname(), "向日葵") == 0) {
				QPointF posto = yard[i][j].map[0]->getitem()->pos();
				ssh[shineindex] = new SunShine(gImageCache->load("interface/Sun.gif"));
				ssh[shineindex]->setPos(posto.x() + 30, posto.y());
				addItem(ssh[shineindex]);
				shineindex++;
			}
		}
	}
}

void GameScene::peashoo(){
	GifItem*peas[20];
	QPropertyAnimation *animationpea[20];
	for (int i = 0; i < 20; i++) {
		peas[i] = NULL;
		animationpea[i] = NULL;
	}
	int peasindex = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (yard[i][j].map[0] != NULL && strstr(yard[i][j].map[0]->getname(), "射手") != NULL) {
				QPointF posfr = yard[i][j].map[0]->getitem()->pos();				
				QPointF posto(0,0);
				for (int p = j + 1; p < 9; p++) {
					if (yard[i][p].map[0] != NULL && yard[i][p].map[0]->gettype() == 2) {
						posto= yard[i][p].map[0]->getitem()->pos();
						break;
					}
				}
				if (posto.x() != 0) {
					if(strcmp(yard[i][j].map[0]->getname(), "豌豆射手")==0)
						peas[peasindex] = new GifItem("images/Plants/PB10.gif");
					else
						peas[peasindex] = new GifItem("images/Plants/PB-10.gif");
					peas[peasindex]->setPos(posfr.x() + 35, posfr.y());
					addItem(peas[peasindex]);
					animationpea[peasindex] = new QPropertyAnimation(peas[peasindex], "pos");
					animationpea[peasindex]->setDuration(500);
					animationpea[peasindex]->setStartValue(QPoint(posfr.x() + 35, posfr.y()));
					animationpea[peasindex]->setEndValue(QPoint(posto.x()+15, posfr.y()));
					animationpea[peasindex]->setEasingCurve(QEasingCurve::OutCubic);
					connect(animationpea[peasindex], &QPropertyAnimation::finished, this, [=] {
						delete peas[peasindex];
					});
					animationpea[peasindex]->start(QAbstractAnimation::DeleteWhenStopped);
					peasindex++;
				}
			}

		}
	}
}

int GameScene::selectZombies(long s, int rd){
	float st = s;
	float rdd = rd;
	if (rdd >= 0 && rdd <= 100 * (35 / st))
		return 0;//普通
	if (rdd > 100 * (35 / st) && rdd <= 100 * ((70 + st / 35) / st))
		return 1;//路障
	if (rdd > 100 * ((70 + st / 35) / st) && rdd <= 50 + 50 * ((70 + st / 35) / st))
		return 3;//报纸
	if (rdd > 90 && rdd <= 100)
		return 4;//小丑
	return 0;
}

void GameScene::Zombiesattack(){
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (yard[i][j].map[0] != NULL && yard[i][j].map[0]->pztype == 2) {
				for (int k = 0; k < yard[i][j].num; k++) {
					if (strcmp(yard[i][j].map[k]->getname(), "小丑僵尸") == 0 && j < 8) {
						default_random_engine random3(time(NULL));
						uniform_int_distribution<int> dis3(0, 100);
						if ((dis3(random3) % 100) <= 10) {//炸毁临近9块地的植物
							for (int p = i - 1; p < i + 2; p++) {
								for (int q = j - 1; q < j + 2; q++) {
									if (p >= 0 && p <= 4 && q >= 0 && q <= 8) {
										if ((yard[p][q].map[0] != NULL && yard[p][q].map[0]->pztype == 1) || yard[p][q].ground == true) {
											if (yard[p][q].ground == false) {
												removeItem(yard[p][q].map[0]->getitem());
												delete[]yard[p][q].map[0];
												yard[p][q].map[0] = NULL;
												yard[p][q].num = 0;
											}
											else {
												yard[p][q].ground = false;
												yard[p][q].HP = 0;
											}
										}
										//onChoose2(11 * (q)+1, 4 * (p)+1);
									}
								}//炸完了
							}
							
							QPointF pos = yard[i][j].map[k]->getitem()->pos();
							QString tempgif=yard[i][j].map[k]->diez();
							GifItem *tg = new GifItem(tempgif);
							tg->setPos(pos);
							GifItem *tg2 = new GifItem("images/Zombies/Zombie/ZombieHead");
							tg2->setPos(pos);
							addItem(tg);
							addItem(tg2);
							if (k < yard[i][j].num - 1)
								delete[]yard[i][j].map[k];
							yard[i][j].map[k] = NULL;
							for (int t = k; t < yard[i][j].num - 1; t++) {
								yard[i][j].map[t] = yard[i][j].map[t + 1];
							}
							yard[i][j].map[yard[i][j].num - 1] = NULL;

							yard[i][j].num--;
						}
					}
				}

			}
		}
	}
}

void GameScene::moveZombies(long long ms){
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (yard[i][j].map[0] != NULL && yard[i][j].map[0]->pztype == 2) {
				if (j == 0) { islose = true; return; }
				if (yard[i][j - 1].ground == true) {
					int atn = 0;
					for (int k = 0; k < yard[i][j].num; k++) {//moveitem
						int xtemp = yard[i][j].map[k]->getitem()->pos().x();
						int ytemp = yard[i][j].map[k]->getitem()->pos().y();
						int spd = 20 / (yard[i][j].map[k]->getSPD() * 8);
						yard[i][j].map[k]->getitem()->setPos(xtemp - spd, ytemp);
						
					}
					for (int k = 0; k < yard[i][j].num; k++) {
						if (yard[i][j].map[k]->getwaittime() > ms - 8000 * yard[i][j].map[k]->getSPD())
							break;
						int tempgiftype1 = yard[i][j].map[k]->getgiftype();
						if (yard[i][j].map[k]->attack() == 1) {
							int tempgiftype2 = yard[i][j].map[k]->getgiftype();
							if (tempgiftype1 != tempgiftype2)
								addItem(yard[i][j].map[k]->getitem());
							atn += yard[i][j].map[k]->getATN();
						}
					}
					yard[i][j - 1].HP -= atn;
					if (yard[i][j - 1].HP <= 0) {
						yard[i][j - 1].HP = 0;
						yard[i][j - 1].ground = false;
					}
					int t = yard[i][j].num;
					for (int k = 0; k < t; k++) {
						if (yard[i][j].map[k]->getwaittime() > ms - 8000 * yard[i][j].map[k]->getSPD()) {
							for (int o = 0; o + k < 5; o++) {
								yard[i][j].map[o] = yard[i][j].map[o + k];
								if (k != 0)
									yard[i][j].map[o + k] = NULL;
							}
							break;
						}
						int tempgiftype1 = yard[i][j].map[k]->getgiftype();
						yard[i][j].map[k]->beattacked(10);
						int tempgiftype2 = yard[i][j].map[k]->getgiftype();
						if (yard[i][j].map[k]->getHP() <= 0) {
							QPointF pos = yard[i][j].map[k]->getitem()->pos();
							QString tempgif = yard[i][j].map[k]->diez();
							GifItem *tg = new GifItem(tempgif);
							tg->setPos(pos);
							GifItem *tg2 = new GifItem("images/Zombies/Zombie/ZombieHead");
							tg2->setPos(pos);
							addItem(tg);
							addItem(tg2);
							delete[]yard[i][j].map[k];
							yard[i][j].map[k] = NULL;
							yard[i][j].num--;
						}
						else {
							if (tempgiftype1 != tempgiftype2)
								addItem(yard[i][j].map[k]->getitem());
							yard[i][j - 1].map[yard[i][j - 1].num] = yard[i][j].map[k];
							yard[i][j].map[k] = NULL;
							yard[i][j - 1].map[yard[i][j - 1].num]->setwaittime(ms);
							yard[i][j].num--;
							yard[i][j - 1].num++;
						}
					}
				}
				else if (yard[i][j - 1].map[0] == NULL || yard[i][j - 1].map[0]->pztype == 0) {
					int kk = yard[i][j].num;
					for (int k = 0; k < yard[i][j].num; k++) {//moveitem
						int xtemp = yard[i][j].map[k]->getitem()->pos().x();
						int ytemp = yard[i][j].map[k]->getitem()->pos().y();
						int spd = 20 / (yard[i][j].map[k]->getSPD() * 8);
						yard[i][j].map[k]->getitem()->setPos(xtemp - spd, ytemp);
					}
					for (int k = 0; k < kk; k++) {
						if (yard[i][j].map[k]->getwaittime() > ms - 8000 * yard[i][j].map[k]->getSPD()) {
							for (int o = 0; o + k < 5; o++) {
								yard[i][j].map[o] = yard[i][j].map[o + k];
								if (k != 0)
									yard[i][j].map[o + k] = NULL;

							}
							break;
						}
						if (yard[i][j - 1].map[k] != NULL)
							delete[]yard[i][j - 1].map[k];
						yard[i][j - 1].map[k] = yard[i][j].map[k];
						//delete[]yard[i][j].map[k];
						yard[i][j].map[k] = NULL;
						yard[i][j].num--;
						yard[i][j - 1].num++;
						yard[i][j - 1].map[k]->setwaittime(ms);
					}

				}
				else if (yard[i][j - 1].map[0] != NULL && yard[i][j - 1].map[0]->pztype == 2) {
					int kkk = yard[i][j - 1].num;
					int kk = yard[i][j].num;
					for (int k = 0; k < yard[i][j].num; k++) {//moveitem
						int xtemp = yard[i][j].map[k]->getitem()->pos().x();
						int ytemp = yard[i][j].map[k]->getitem()->pos().y();
						int spd = 20 / (yard[i][j].map[k]->getSPD() * 8);
						yard[i][j].map[k]->getitem()->setPos(xtemp - spd, ytemp);
					}
					for (int k = 0; k < kk; k++) {
						if (yard[i][j].map[k]->getwaittime() > ms - 8000 * yard[i][j].map[k]->getSPD()) {
							for (int o = 0; o + k < 5; o++) {
								yard[i][j].map[o] = yard[i][j].map[o + k];
								if (k != 0)
									yard[i][j].map[o + k] = NULL;
							}
							break;
						}
						if (yard[i][j - 1].map[kkk + k] != NULL)
							delete[]yard[i][j - 1].map[k];
						yard[i][j - 1].map[kkk + k] = yard[i][j].map[k];
						//delete[]yard[i][j].map[k];
						yard[i][j].map[k] = NULL;
						yard[i][j].num--;
						yard[i][j - 1].num++;
						yard[i][j - 1].map[kkk + k]->setwaittime(ms);
					}
				}
				else if (yard[i][j - 1].map[0] != NULL && yard[i][j - 1].map[0]->pztype == 1) {
					if (yard[i][j - 1].map[0]->getHP() <= 0) {
						for (int k = 0; k < yard[i][j].num; k++) {//moveitem
							int xtemp = yard[i][j].map[k]->getitem()->pos().x();
							int ytemp = yard[i][j].map[k]->getitem()->pos().y();
							int spd = 20 / (yard[i][j].map[k]->getSPD() * 8);
							yard[i][j].map[k]->getitem()->setPos(xtemp - spd, ytemp);

						}
						yard[i][j - 1].num = 0;
						int t = yard[i][j].num;
						for (int k = 0; k < t; k++) {
							if (yard[i][j].map[k]->getwaittime() > ms - 8000 * yard[i][j].map[k]->getSPD()) {
								for (int o = 0; o + k < 5; o++) {
									yard[i][j].map[o] = yard[i][j].map[o + k];
									if (k != 0)
										yard[i][j].map[o + k] = NULL;
								}
								break;
							}
							delete[]yard[i][j - 1].map[k];
							yard[i][j - 1].map[k] = yard[i][j].map[k];
							//delete[]yard[i][j].map[k];
							yard[i][j].map[k] = NULL;
							yard[i][j - 1].map[k]->setwaittime(ms);
							yard[i][j].num--;
							yard[i][j - 1].num++;
						}
					}
					else if (strcmp(yard[i][j - 1].map[0]->getname(), "窝瓜") == 0) {
						int kk = yard[i][j].num;
						int k = 0;
						for (; k < kk; k++) {
							if (yard[i][j].map[k]->getwaittime() > ms - 8000 * yard[i][j].map[k]->getSPD()) {
								for (int o = 0; o + k < 5; o++) {
									yard[i][j].map[o] = yard[i][j].map[o + k];
									if (k != 0)
										yard[i][j].map[o + k] = NULL;
								}
								break;
							}
							getpoints(yard[i][j].map[k]->getname());
							QPointF pos = yard[i][j].map[k]->getitem()->pos();
							QString tempgif = yard[i][j].map[k]->diez();						
							GifItem *tg = new GifItem(tempgif);
							tg->setPos(pos);
							GifItem *tg2 = new GifItem("images/Plants/Squash/SquashAttack");
							tg2->setPos(pos.x()+5, pos.y() - 100);
							addItem(tg);
							addItem(tg2);
							delete[]yard[i][j].map[k];
							yard[i][j].map[k] = NULL;
							yard[i][j].num--;
						}
						if (k > 0) {
							removeItem(yard[i][j - 1].map[0]->getitem());
							delete[]yard[i][j - 1].map[0];
							yard[i][j - 1].map[0] = NULL;
							yard[i][j - 1].num = 0;
						}
						for (int k = 0; k < yard[i][j].num; k++) {//moveitem
							int xtemp = yard[i][j].map[k]->getitem()->pos().x();
							int ytemp = yard[i][j].map[k]->getitem()->pos().y();
							int spd = 20 / (yard[i][j].map[k]->getSPD() * 8);
							yard[i][j].map[k]->getitem()->setPos(xtemp - spd, ytemp);

						}
					}
					else if (strcmp(yard[i][j - 1].map[0]->getname(), "土豆地雷") == 0 && yard[i][j - 1].map[0]->getwaittime() <= ms - 10000) {
						int kk = yard[i][j].num;
						getpoints(yard[i][j].map[0]->getname());
						QPointF pos = yard[i][j].map[0]->getitem()->pos();
						GifItem *tg3 = new GifItem("images/Zombies/Zombie/BoomDie");
						tg3->setPos(pos);
						addItem(tg3);

						delete[]yard[i][j].map[0];
						yard[i][j].map[0] = NULL;
						yard[i][j].num--;
						removeItem(yard[i][j - 1].map[0]->getitem());
						delete[]yard[i][j - 1].map[0];
						yard[i][j - 1].map[0] = NULL;
						yard[i][j - 1].num = 0;
						for (int k = 0; k < kk - 1; k++) {
							if (yard[i][j].map[k + 1]->getwaittime() > ms - 8000 * yard[i][j].map[k + 1]->getSPD()) {
								for (int o = 0; o + k < 5; o++) {
									yard[i][j].map[o] = yard[i][j].map[o + k];
									if (k != 0)
										yard[i][j].map[o + k] = NULL;
								}
								break;
							}
							yard[i][j - 1].map[k] = yard[i][j].map[k + 1];
							yard[i][j].map[k + 1] = NULL;
							yard[i][j - 1].num++;
							yard[i][j - 1].map[k]->setwaittime(ms);
							yard[i][j].num--;
						}
						for (int k = 0; k < yard[i][j].num; k++) {//moveitem
							int xtemp = yard[i][j].map[k]->getitem()->pos().x();
							int ytemp = yard[i][j].map[k]->getitem()->pos().y();
							int spd = 20 / (yard[i][j].map[k]->getSPD() * 8);
							yard[i][j].map[k]->getitem()->setPos(xtemp - spd, ytemp);

						}

					}
					else if (strcmp(yard[i][j - 1].map[0]->getname(), "地刺") == 0) {
						for (int k = 0; k < yard[i][j].num; k++) {//moveitem
							int xtemp = yard[i][j].map[k]->getitem()->pos().x();
							int ytemp = yard[i][j].map[k]->getitem()->pos().y();
							int spd = 20 / (yard[i][j].map[k]->getSPD() * 8);
							yard[i][j].map[k]->getitem()->setPos(xtemp - spd, ytemp);
						}
						int atn = 0;
						yard[i][j - 1].num = 0;
						for (int k = 0; k < yard[i][j].num; k++) {
							if (yard[i][j].map[k]->getwaittime() > ms - 8000 * yard[i][j].map[k]->getSPD())
								break;
							int tempgiftype1 = yard[i][j].map[k]->getgiftype();
							if (yard[i][j].map[k]->attack() == 1) {
								int tempgiftype2 = yard[i][j].map[k]->getgiftype();
								if (tempgiftype1 != tempgiftype2)
									addItem(yard[i][j].map[k]->getitem());
								atn += yard[i][j].map[k]->getATN();
							}
						}
						yard[i][j - 1].map[0]->beattacked(atn);
						yard[i][j - 1].HP -= atn;
						if (yard[i][j - 1].map[0]->getHP() <= 0) {
							yard[i][j - 1].ground = false;
							yard[i][j - 1].HP = 0;
						}
						delete[]yard[i][j - 1].map[0];
						yard[i][j - 1].map[0] = NULL;
						int t = yard[i][j].num;
						for (int k = 0; k < t; k++) {
							if (yard[i][j].map[k]->getwaittime() > ms - 8000 * yard[i][j].map[k]->getSPD()) {
								for (int o = 0; o + k < 5; o++) {
									yard[i][j].map[o] = yard[i][j].map[o + k];
									if (k != 0)
										yard[i][j].map[o + k] = NULL;
								}
								break;
							}
							int tempg1 = yard[i][j].map[k]->getgiftype();
							yard[i][j].map[k]->beattacked(10);
							int tempg2 = yard[i][j].map[k]->getgiftype();
							if (yard[i][j].map[k]->getHP() <= 0) {
								getpoints(yard[i][j].map[k]->getname());
								QPointF pos = yard[i][j].map[k]->getitem()->pos();
								QString tempgif = yard[i][j].map[k]->diez();
								GifItem *tg = new GifItem(tempgif);
								tg->setPos(pos);
								addItem(tg);
								GifItem *tg2 = new GifItem("images/Zombies/Zombie/ZombieHead");
								tg2->setPos(pos);
								addItem(tg2);
								delete[]yard[i][j].map[k];
								yard[i][j].map[k] = NULL;
								yard[i][j].num--;
							}
							else {
								if (tempg1 != tempg2)
									addItem(yard[i][j].map[k]->getitem());
								yard[i][j - 1].map[yard[i][j - 1].num] = yard[i][j].map[k];
								yard[i][j].map[k] = NULL;
								yard[i][j - 1].map[yard[i][j - 1].num]->setwaittime(ms);
								yard[i][j].num--;
								yard[i][j - 1].num++;
							}
						}
					}
					else {//攻击,不攻击的move
						for (int k = 0; k < yard[i][j].num; k++) {
							if (yard[i][j].map[k]->getwaittime() > ms - 8000 * yard[i][j].map[k]->getSPD()) {
								int xtemp = yard[i][j].map[k]->getitem()->pos().x();
								int ytemp = yard[i][j].map[k]->getitem()->pos().y();
								int spd = 20 / (yard[i][j].map[k]->getSPD() * 8);
								yard[i][j].map[k]->getitem()->setPos(xtemp - spd, ytemp);
							}
						}
						int atn = 0;
						for (int k = 0; k < yard[i][j].num; k++) {
							if (yard[i][j].map[k]->getwaittime() > ms - 8000 * yard[i][j].map[k]->getSPD())
								break;
							int tempgiftype1 = yard[i][j].map[k]->getgiftype();
							if (yard[i][j].map[k]->attack() == 1) {
								int tempgiftype2 = yard[i][j].map[k]->getgiftype();
								if (tempgiftype1 != tempgiftype2)
									addItem(yard[i][j].map[k]->getitem());
								atn += yard[i][j].map[k]->getATN();
							}
						}
						yard[i][j - 1].map[0]->beattacked(atn);//here
						if (yard[i][j - 1].map[0]->getHP() <= 0) {
							removeItem(yard[i][j - 1].map[0]->getitem());
							delete[]yard[i][j - 1].map[0];
							yard[i][j - 1].num = 0;

							int t = yard[i][j].num;
							for (int k = 0; k < t; k++) {
								if (yard[i][j].map[k]->getwaittime() > ms - 8000 * yard[i][j].map[k]->getSPD()) {
									for (int o = 0; o + k < 5; o++) {
										yard[i][j].map[o] = yard[i][j].map[o + k];
										if (k != 0)
											yard[i][j].map[o + k] = NULL;
									}
									break;
								}
								yard[i][j].map[k]->backitem();
								addItem(yard[i][j].map[k]->getitem());
								yard[i][j - 1].map[k] = yard[i][j].map[k];
								yard[i][j].map[k] = NULL;
								yard[i][j - 1].map[k]->setwaittime(ms);
								yard[i][j].num--;
								yard[i][j - 1].num++;
							}
						}
						else {//没打死怎么办,先不怎么办

						}
					}
				}
			}
		}
	}
}

void GameScene::Plantsattack(){
	for (int i = 0; i < 5; i++) {
		int atn = 0;
		bool ice = false;
		for (int j = 0; j < 9; j++) {
			if (yard[i][j].map[0] != NULL && strcmp(yard[i][j].map[0]->getname(), "樱桃炸弹") == 0) {
				GifItem *tg3[40];
				for (int iig = 0; iig < 40; iig++)
					tg3[iig] = NULL;
				int gifindex = 0;
				for (int p = -1; p <= 1; p++) {
					for (int q = -1; q <= 1; q++) {
						if (i + p < 0 || i + p>4 || j + q < 0 || j + q>8)
							continue;
						//onChoose2(11 * (j + q) + 1, 4 * (i + p) + 1);
						if (yard[i + p][j + q].map[0] != NULL && yard[i + p][j + q].map[0]->pztype == 2) {
							for (int t = 0; t < yard[i + p][j + q].num; t++) {
								getpoints(yard[i + p][j + q].map[t]->getname());
								QPointF pos = yard[i + p][j + q].map[t]->getitem()->pos();
								yard[i + p][j + q].map[t]->diez();
								tg3[gifindex] = new GifItem("images/Zombies/Zombie/BoomDie");
								tg3[gifindex]->setPos(pos);
								addItem(tg3[gifindex]);
								gifindex++;
								delete[]yard[i + p][j + q].map[t];
								yard[i + p][j + q].map[t] = NULL;
							}
							yard[i + p][j + q].num = 0;
						}
					}
				}
				removeItem(yard[i][j].map[0]->getitem());
				delete[]yard[i][j].map[0];
				yard[i][j].map[0] = NULL;
				yard[i][j].num = 0;
				//board_color();
			}
			else if (yard[i][j].map[0] != NULL && strcmp(yard[i][j].map[0]->getname(), "火爆辣椒") == 0) {
				GifItem *tg3[40];
				for (int iig = 0; iig < 40; iig++)
					tg3[iig] = NULL;
				int gifindex = 0;
				for (int p = 0; p < 8; p++) {
					if (yard[i][p].map[0] != NULL && yard[i][p].map[0]->pztype == 2) {
						for (int t = 0; t < yard[i][p].num; t++) {
							getpoints(yard[i][p].map[t]->getname());
							QPointF pos = yard[i][p].map[t]->getitem()->pos();
							yard[i][p].map[t]->diez();
							tg3[gifindex] = new GifItem("images/Zombies/Zombie/BoomDie");
							tg3[gifindex]->setPos(pos);
							addItem(tg3[gifindex]);
							gifindex++;
							delete[]yard[i][p].map[t];
							yard[i][p].map[t] = NULL;
						}
						yard[i][p].num = 0;
					}
				}
				removeItem(yard[i][j].map[0]->getitem());
				delete[]yard[i][j].map[0];
				yard[i][j].map[0] = NULL;
				yard[i][j].num = 0;
				//board_color();
				break;
			}
			else {
				if (yard[i][j].map[0] != NULL && strcmp(yard[i][j].map[0]->getname(), "寒冰射手") == 0)
					ice = true;
				if (yard[i][j].map[0] != NULL && yard[i][j].map[0]->pztype == 1 && yard[i][j].map[0]->getplantstype() == 0 && yard[i][j].map[0]->getHP() > 0)
					atn += yard[i][j].map[0]->getATN();
				else if (yard[i][j].map[0] != NULL && yard[i][j].map[0]->pztype == 2 && atn != 0) {
					int temp = yard[i][j].num;
					if (ice) {
						for (int kk = 0; kk < temp; kk++) {
							double a = yard[i][j].map[kk]->getSPD();
							yard[i][j].map[kk]->setSPD(a * 1.05);
						}
					}
					int ttem = temp;
					int k = 0;
					for (; k < temp; k++) {
						if (atn >= yard[i][j].map[k]->getHP()) {
							atn -= yard[i][j].map[k]->getHP();
							yard[i][j].map[k]->beattacked(MAX_ATN);
							getpoints(yard[i][j].map[k]->getname());
							yard[i][j].num--;
						}
						else {
							int tempg1 = yard[i][j].map[k]->getgiftype();
							yard[i][j].map[k]->beattacked(atn);
							int tempg2 = yard[i][j].map[k]->getgiftype();
							if (tempg1 != tempg2)
								addItem(yard[i][j].map[k]->getitem());
							break;
						}
					}
					if (k > 0) {
						for (int p = 0; p < k; p++) {
							QPointF pos = yard[i][j].map[p]->getitem()->pos();
							
							QString tempgif=yard[i][j].map[p]->diez();
							GifItem *tg = new GifItem(tempgif);
							tg->setPos(pos);
							addItem(tg);
							GifItem *tg2 = new GifItem("images/Zombies/Zombie/ZombieHead");
							tg2->setPos(pos);
							addItem(tg2);
							delete[]yard[i][j].map[p];
						}
						int t = 0;
						for (; k + t < temp; t++) {
							yard[i][j].map[t] = yard[i][j].map[t + k];
						}
						for (; t < temp; t++) {//////??????????????
							yard[i][j].map[t] = NULL;
						}
					}
					atn = 0;
					ice = false;
				}
			}
		}
	}
}

void GameScene::getpoints(char * n){
	if (strcmp(n, "僵尸") == 0)
		sumPoint += 20;
	else if (strcmp(n, "路障僵尸") == 0)
		sumPoint += 25;
	else if (strcmp(n, "摇旗僵尸") == 0)
		sumPoint += 20;
	else if (strcmp(n, "小丑僵尸") == 0)
		sumPoint += 30;
	else if (strcmp(n, "读报僵尸") == 0)
		sumPoint += 35;
	else
		sumPoint += 0;
}

