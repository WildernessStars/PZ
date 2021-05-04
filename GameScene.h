#pragma once
//
// Created by sun on 8/26/16.
//

#include <QtWidgets>
#include"store.h"

class Plant;
class Zombie;
class PlantCardItem;
class PlantCardAvalible;
class Zombie;
class GifItem;
class myPixmap;
class MyPixItem;
class PZ;


class GameScene : public QGraphicsScene
{
	Q_OBJECT

public:
	GameScene();
	~GameScene();
	void loadReady();
	
	int selectZombies(long s, int rd);
	void Zombiesattack();//小丑僵尸
	void moveZombies(long long ms);//往前走发现有植物再攻击，平时不会攻击，太惨了
	void Plantsattack();
	void getpoints(char *n);
protected:
	void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
	void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
signals:
	void mouseMove(QGraphicsSceneMouseEvent *mouseEvent);
	void mousePress(QGraphicsSceneMouseEvent *mouseEvent);
	void mouseRelease(QGraphicsSceneMouseEvent *mouseEvent);

private:
	bool islose;
	int sumPoint;
	PZ *p;//Plant setting pos
	QPointF settingpos;
	Store mystore;
	struct Yard {
		PZ *map[10];
		int num;
		bool ground;
		int HP;
	};
	Yard yard[5][10];
	
	myPixmap *background;
	MyPixItem *backmenu;
	QGraphicsPixmapItem *shovel;
	QGraphicsPixmapItem *shovelBack;
	QGraphicsPixmapItem *SunBack;
	QGraphicsTextItem *SumSun;
	QTimer *timer1;
	QTimer *timer2;
	QTimer *timer3;
	QTimer *timer4;
	QTimer *timer5;
	QTimer *timer6;
	
	struct CardGraphicsItem {
		PlantCardItem *plantCard;
		PlantCardAvalible *plantAvalible;
	};
	QList<CardGraphicsItem > cardGraphics;
	struct CardSelected {
		int kind;
		MyPixItem *SelectedCard;
	} cardselected;
public slots:
	void gameattack();
	void gamemove();
	void produceFirstZombie();
	void produceZombies();
	void countdown();
	void produceSunshine();
	void peashoo();
};

