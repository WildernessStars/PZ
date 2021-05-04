#pragma once
#pragma once
#include<iostream>
#include "PZ.h"
#include <QtCore>
#include <QtWidgets>
#include "GifItem.h"
using namespace std;
#pragma warning(disable:4996)

#define ONE_FRAME 1
#define ATTACK_TYPE 0
#define DEFEND_TYPE 1
#define BOMB_TYPE 2
#define EFFECT_TYPE 3


class Plants :public PZ {
	int type;
	int HP;
	int nowHP;
	int ATN;
	int CD;
	char name[20];
	int waittime;
	char card[30];
public:
	int gif;
	GifItem *item;
	int sunshine;
	pair<int, int> position;
	bool is_alive;
	Plants(int typ, int sun, int hp, int atn, int cd) :PZ(1) {
		type = typ; sunshine = sun; HP = hp; nowHP = hp; ATN = atn; CD = cd;
		is_alive = true; waittime = 0;
	}
	char * getcard() { return card; }
	void setpos(pair<int, int> p) { position = p; }
	void setName(const char a[]) { strcpy(name, a); }
	char * getname() { return name; }
	char * getStageName() { char *a = NULL; return a; }
	void changeHP(int i) { nowHP = nowHP - i; if (nowHP <= 0)	is_alive = false; }
	int getHP() { return nowHP; }
	int getoriginalHP() { return HP; }
	int getplantstype() { return type; }
	int getATN() { return ATN; }
	int getCD() { return CD; }
	int getwaittime() { return waittime; }
	void setwaittime(int i) { waittime = i; }
	GifItem *getitem() { return item; }
	int getgiftype() { return gif; }
	void backitem() {}
	char* diez() { return name; }
	void beattack(int i){}
};

class Pea_Shooter : public Plants {
public:
	int ball_num;
	Pea_Shooter(int num) :Plants(ATTACK_TYPE, 100 * num, 500 * num, 20, 3 * num) {
		if (num == 1) {
			setName("Íã¶¹ÉäÊÖ");
			item = new GifItem("images/Plants/Peashooter/Peashooter.gif");
		}
		else {
			setName("Ë«Íã¶¹ÉäÊÖ");
			item = new GifItem("images/Plants/Repeater/Repeater.gif");
		}
		ball_num = num;

	}
	int attack() {
		if (is_alive == true) {
			return getATN();
		}
		return 0;
	}
	void beattacked(int i) {
		changeHP(i);
	}

	~Pea_Shooter() { delete item; }
};

class Ice_Shooter : public Plants {
public:
	Ice_Shooter() :Plants(ATTACK_TYPE, 150, 500, 20, 3) {
		setName("º®±ùÉäÊÖ");
		item = new GifItem("images/Plants/SnowPea/SnowPea.gif");
	}
	int attack() {
		if (is_alive == true) {
			//PlantBall temp(1, ONE_FRAME, 20,position);
			return 3;
		}
		return 0;
	}
	void beattacked(int i) {
		changeHP(i);
	}

	~Ice_Shooter() { delete item; }
};

class Ground_Thorn : public Plants {
public:
	Ground_Thorn() :Plants(ATTACK_TYPE, 50, 300, 10, 3) {
		setName("µØ´Ì");
		item = new GifItem("images/Plants/Spikeweed/Spikeweed.gif");
	}
	int attack() {
		if (is_alive == true)
			return 1;
		return 0;
	}
	void beattacked(int i) {
		changeHP(i);
	}

	~Ground_Thorn() { delete item; }
};

class High_Nut : public Plants {
public:
	string gif1 = "images/Plants/TallNut/TallnutCracked1.gif";
	string gif2 = "images/Plants/TallNut/TallnutCracked2.gif";
	High_Nut() :Plants(DEFEND_TYPE, 100, 5000, 0, 6) {
		setName("¸ß¼á¹û");
		item = new GifItem("images/Plants/TallNut/TallNut.gif");
	}
	void beattacked(int i) {
		changeHP(i);
	}

	~High_Nut() { delete item; }
};

class Squash : public Plants {
public:
	string gif1 = "images/Plants/Squash/SquashR.gif";
	string gif2 = "images/Plants/Squash/SquashAttack.gif";
	Squash() :Plants(BOMB_TYPE, 50, 3000, 1000, 6) {
		setName("ÎÑ¹Ï");
		item = new GifItem("images/Plants/Squash/Squash.gif");
	}
	int attack() {
		if (is_alive == true)
			return 1;
		return 0;
	}
	void beattacked(int i) {
		changeHP(i);
	}

	~Squash() { delete item; }
};

class Potato_Mine : public Plants {
	int countdown;
public:
	string gif1 = "images/Plants/PotatoMine/PotatoMine.gif";
	string gif2 = "images/Plants/PotatoMine/PotatoMine_mashed.gif";
	Potato_Mine() :Plants(BOMB_TYPE, 50, 3000, 0, 3) {
		countdown = 10;
		setName("ÍÁ¶¹µØÀ×");
		item = new GifItem("images/Plants/PotatoMine/PotatoMineNotReady.gif");
	}
	int attack() {
		if (is_alive == true)
			return 1;
		return 0;
	}
	bool count() {
		countdown--;
		if (countdown == 0)
			return true;
		return false;
	}
	void beattacked(int i) {
		changeHP(i);
	}

	~Potato_Mine() { delete item; }
};

class Cherry_Bomb : public Plants {
public:
	string gif1 = "images/Plants/CherryBomb/Boom.gif";
	Cherry_Bomb() :Plants(BOMB_TYPE, 150, 3000, 1000, 8) {
		setName("Ó£ÌÒÕ¨µ¯");
		item = new GifItem("images/Plants/CherryBomb/CherryBomb.gif");
	}
	int attack() {
		if (is_alive == true)
			return 1;
		return 0;
	}
	void beattacked(int i) {
		changeHP(i);
	}
	~Cherry_Bomb() { delete item; }
};

class Hot_Pepper : public Plants {
public:
	string gif1 = "images/Plants/Jalapeno/JalapenoAttack.gif";
	Hot_Pepper() :Plants(BOMB_TYPE, 150, 3000, 1000, 8) {
		setName("»ð±¬À±½·");
		item = new GifItem("images/Plants/Jalapeno/Jalapeno.gif");
	}
	int attack() {
		if (is_alive == true)
			return 1;
		return 0;
	}
	void beattacked(int i) {
		changeHP(i);
	}
	~Hot_Pepper() { delete item; }
};

class Sunflower : public Plants {
public:
	Sunflower() :Plants(EFFECT_TYPE, 50, 100, 0, 2) {
		setName("ÏòÈÕ¿û");
		item = new GifItem("images/Plants/SunFlower/SunFlower1.gif");
	}
	int effect();
	void beattacked(int i) {
		changeHP(i);
	}
	~Sunflower() { delete item; }
};