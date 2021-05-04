#pragma once
#pragma once
#include<iostream>
#include "GifItem.h"
#include  <time.h>  
#include "PZ.h"
using namespace std;

#define HALF_FRAME 0.5
#define ONE_FRAME 0.25

class Zombies :public PZ {
	int HP;
	int ATN;
	double SPD;
	int waittime;
	char name[20];
	char stagename[10];
public:
	int gif;
	GifItem *item;
	pair<int, int> position;
	bool is_alive;
	bool stage;
	Zombies(int hp, int atn, double spd) :PZ(2) {
		HP = hp; ATN = atn; SPD = spd; waittime = 0;
		is_alive = true; stage = false;
	}
	void setpos(pair<int, int> p) { position = p; }
	char* getname() { return name; }
	char* getStageName() { return stagename; }
	void setName(const char a[]) { strcpy(name, a); }
	void setStageName(const char a[]) { strcpy(stagename, a); }
	void setSPD(double a) { SPD = a; }
	void changeHP(int i) { HP = HP - i; if (HP <= 0)	is_alive = false; }
	int getHP() { return HP; }
	int getATN() { return ATN; }
	double getSPD() { return SPD; }
	void changeSPD(int i) { SPD = i; }
	bool havestage() { return stage; }
	int getwaittime() { return waittime; }
	void setwaittime(int i) { waittime = i; }
	char* diez() { return name; }
	GifItem* getitem() { return item; }
	int getgiftype() { return gif; }
	void backitem(){}
};

class normal_Zombies :public Zombies {
public:
	
	
	normal_Zombies() :Zombies(80, 20, HALF_FRAME) {
		setName("½©Ê¬");
		item = new GifItem("images/Zombies/Zombie/Zombie3.gif");
		gif = 0;
	}
	int attack() {
		if (is_alive == true) {
			//qDebug() << "change";
			if (gif != 1) {
				QPointF po = item->pos();
				delete item;
				item = new GifItem("images/Zombies/Zombie/ZombieAttack.gif");
				item->setPos(po);
				gif = 1;
			}
			return 1;
		}
		return 0;
	}
	void beattacked(int i) {
		changeHP(i);
	}
	void backitem() {
		QPointF po = item->pos();
		delete item;
		item = new GifItem("images/Zombies/Zombie/Zombie3.gif");
		item->setPos(po);
		gif = 0;
	}
	char* diez() {
		delete item;
		item = NULL;
		return "images/Zombies/Zombie/ZombieDie.gif";
	}
	~normal_Zombies() { if (item != NULL)	delete item; }
};
class roadblock_Zombies :public Zombies {
	
public:
	 
	roadblock_Zombies() :Zombies(120, 20, HALF_FRAME) {
		setName("Â·ÕÏ½©Ê¬"); setStageName("Â·ÕÏ"); stage = true;
		item = new GifItem("images/Zombies/ConeheadZombie/ConeheadZombie.gif");
		gif = 0;
	}
	int attack() {
		if (is_alive == true) {
			if (gif != 1 && gif != 2) {
				QPointF po = item->pos();
				delete item;//qDebug() << "coneheadattack";
				if (stage) {
					item = new GifItem("images/Zombies/Zombie/ConeheadZombieAttack.gif");
					gif = 1;
				}
				else {
					item = new GifItem("images/Zombies/Zombie/ZombieAttack.gif");
					gif = 2;
				}
				item->setPos(po);
			}
			return 1;
		}
		return 0;
	}
	void beattacked(int i) {
		changeHP(i);
		if (getHP() <= 80) {
			stage = false;
			if (gif != 3) {
				QPointF po = item->pos();
				delete item;
				//qDebug() << "coneheadbeattack";
				item = new GifItem("images/Zombies/Zombie/Zombie3.gif");
				item->setPos(po);
				gif = 3;
			}
		}
	}
	void backitem() {
		QPointF po = item->pos();
		delete item;
		if(getHP() <= 80)
			item = new GifItem("images/Zombies/Zombie/Zombie3.gif");
		else
			item = new GifItem("images/Zombies/ConeheadZombie/ConeheadZombie.gif");
		item->setPos(po);
		gif = 0;
	}
	char* diez() {
		delete item;
		item = NULL;
		return "images/Zombies/Zombie/ZombieDie.gif";
	}
	~roadblock_Zombies() { if (item != NULL)	delete item; }
};

class flag_Zombies :public Zombies {
	bool stage;
public:
	 
	flag_Zombies() :Zombies(140, 20, HALF_FRAME) { 
		setName("Ò¡Æì½©Ê¬"); setStageName("ÆìÖÄ"); stage = true; 
		item = new GifItem("images/Zombies/FlagZombie/FlagZombie.gif");
		gif = 0;
	}
	int attack() {
		if (is_alive == true) {
			if (gif != 1) {
				QPointF po = item->pos();
				delete item;
				item = new GifItem("images/Zombies/FlagZombie/FlagZombieAttack.gif");
				item->setPos(po);
				gif = 1;
			}
			return 1;
		}
		return 0;
	}
	void beattacked(int i) {
		changeHP(i);
		if (getHP() <= 80) {
			stage = false;
		}
	}
	void backitem() {
		QPointF po = item->pos();
		delete item;
		item = new GifItem("images/Zombies/FlagZombie/FlagZombie.gif");
		item->setPos(po);
		gif = 0;
	}
	char* diez() {
		//qDebug() << "here";
		delete item;
		item = NULL;
		return "images/Zombies/Zombie/ZombieDie.gif";
	}
	~flag_Zombies() { if (item != NULL)	delete item; }
};
class clown_Zombies :public Zombies {
public:
	 
	string path1 = "images/Zombies/JackinTheBoxZombie/Boom.gif";
	string path2 = "images/Zombies/JackinTheBoxZombie/BoomDie.gif";
	clown_Zombies() :Zombies(100, 20, HALF_FRAME) { 
		setName("Ð¡³ó½©Ê¬");
		item = new GifItem("images/Zombies/JackinTheBoxZombie/Walk.gif");
		gif = 0;
	}
	int attack() {
		srand((unsigned)time(NULL));
		int rd = (rand() % 100);
		if (is_alive == true && rd > 80) {
			if (gif != 1) {
				QPointF po = item->pos();
				delete item;
				item = new GifItem("images/Zombies/JackinTheBoxZombie/GoOut.gif");
				item->setPos(po);
				gif = 1;
			}
			return 2;
		}
		else if (is_alive == true) {
			if (gif != 2) {
				QPointF po = item->pos();
				delete item;
				item = new GifItem("images/Zombies/JackinTheBoxZombie/Attack.gif");
				item->setPos(po);
				gif = 2;
			}
			return 1;
		}
		return 0;
	}
	void beattacked(int i) {
		changeHP(i);
	}
	void backitem() {
		QPointF po = item->pos();
		delete item;
		item = new GifItem("images/Zombies/JackinTheBoxZombie/Walk.gif");
		item->setPos(po);
		gif = 0;
	}
	char* diez() {
		delete item;
		item = NULL;
		return "images/Zombies/JackinTheBoxZombie/Die.gif";
	}
	~clown_Zombies() { if (item != NULL)	delete item; }
};
class newspaper_Zombies :public Zombies {
	bool stage;
public:
	 
	newspaper_Zombies() :Zombies(140, 20, HALF_FRAME) {
		setName("¶Á±¨½©Ê¬"); setStageName("±¨Ö½"); stage = true;
		item = new GifItem("images/Zombies/NewspaperZombie/HeadWalk1.gif");
		gif = 0;
	}
	int attack() {
		if (is_alive == true) {
			if (gif != 1 && gif != 2) {
				QPointF po = item->pos();
				delete item;
				if (stage) {
					item = new GifItem("images/Zombies/NewspaperZombie/HeadAttack1.gif");
					gif = 1;
				}
				else {
					item = new GifItem("images/Zombies/NewspaperZombie/HeadAttack0.gif");
					gif = 2;
				}
				item->setPos(po);
			}
			return 1;
		}
		return 0;
	}
	void beattacked(int i) {
		changeHP(i);
		if (getHP() <= 80) {
			if (gif != 3) {
				QPointF po = item->pos();
				delete item;
				item = new GifItem("images/Zombies/NewspaperZombie/HeadWalk0.gif");
				item->setPos(po);
				gif = 3;
			}
			stage = false;
			changeSPD(ONE_FRAME);
		}
	}
	void backitem() {
		QPointF po = item->pos();
		delete item;
		item = new GifItem("images/Zombies/NewspaperZombie/HeadWalk1.gif");
		item->setPos(po);
		gif = 0;
	}
	char* diez() {
		delete item;
		item = NULL;
		return "images/Zombies/NewspaperZombie/Die.gif";
	}
	~newspaper_Zombies() { if (item != NULL)	delete item; }
};
