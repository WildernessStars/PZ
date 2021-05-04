#pragma once
#include<iostream>
using namespace std;

class Store {
	//char name[15][20];
	int num;
public:
	int cd[10];
	int CD[10];
	int price[10];
	Store() {
		num = 9;
	
		price[0] = 100;
		price[1] = 50;
		price[2] = 150;
		price[3] = 100;
		price[4] = 50;
		price[5] = 50;
		price[6] = 150;
		price[7] = 150;
		price[8] = 50;

		CD[0] = 3;
		CD[1] = 2;
		CD[2] = 3;
		CD[3] = 4;
		CD[4] = 4;
		CD[5] = 4;
		CD[6] = 5;
		CD[7] = 5;
		CD[8] = 5;
		
		for (int i = 0; i < num; i++) {
			cd[i] = CD[i];
		}
	}
	void countdown() {
		for (int i = 0; i < num; i++) {
			if (cd[i] != 0)
				cd[i]--;
		}
	}

	bool getPea_1() {
		if (cd[0] == 0) {
			//setting_pos = new Pea_Shooter(1);
			cd[0] = CD[0];
			return 1;
		}
		return 0;
	}
	bool getPea_2() {
		if (cd[1] == 0) {
			//setting_pos = new Pea_Shooter(2);
			cd[1] = CD[1];
			return 1;
		}
		return 0;
	}
	bool getIce() {
		if (cd[2] == 0) {
			//setting_pos = new Ice_Shooter;
			cd[2] = CD[2];
			return 1;
		}
		return 0;
	}
	bool getGround() {
		if (cd[4] == 0) {
			//setting_pos = new Ground_Thorn;
			cd[4] = CD[4];
			return 1;
		}
		return 0;
	}
	bool getHNut() {
		if (cd[5] == 0) {
			//setting_pos = new High_Nut;
			cd[5] = CD[5];
			return 1;
		}
		return 0;
	}
	bool getSquash() {
		if (cd[6] == 0) {
		//	setting_pos = new Squash;
			cd[6] = CD[6];
			return 1;
		}
		return 0;
	}
	bool getPotato() {
		if (cd[7] == 0) {
			//setting_pos = new Potato_Mine;
			cd[7] = CD[7];
			return 1;
		}
		return 0;
	}
	bool getCherry() {
		if (cd[8] == 0) {
			//setting_pos = new Cherry_Bomb;
			cd[8] = CD[8];
			return 1;
		}
		return 0;
	}
	bool getPepper() {
		if (cd[9] == 0) {
			//setting_pos = new Hot_Pepper;
			cd[9] = CD[9];
			return 1;
		}
		return 0;
	}
	bool getSun() {
		if (cd[10] == 0) {
			//setting_pos = new Sunflower;
			cd[10] = CD[10];
			return 1;
		}
		return 0;
	}
	bool getPlants(int sum_sunshine,pair<int, int> p);
	
}; 