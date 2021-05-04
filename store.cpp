#include "store.h"

bool Store::getPlants(int sum_sunshine,pair<int, int> p){
	int x = p.first;
	int y = p.second;
	if (x == 0 && y == 27) {
		if (sum_sunshine >= price[0]) {
			sum_sunshine -= price[0];
			return getPea_1();
		}
	}
	else if (x == 20 && y == 27) {
		if (sum_sunshine >= price[1]) {
			sum_sunshine -= price[1];
			return getPea_2();
		}
	}
	else if (x == 40 && y == 27) {
		if (sum_sunshine >= price[2]) {
			sum_sunshine -= price[2];
			return getIce();
		}
	}
	else if (x == 0 && y == 28) {
		if (sum_sunshine >= price[4]) {
			sum_sunshine -= price[4];
			return getGround();
		}
	}
	else if (x == 20 && y == 28) {
		if (sum_sunshine >= price[5]) {
			sum_sunshine -= price[5];
			return getHNut();
		}
	}
	else if (x == 40 && y == 28) {
		if (sum_sunshine >= price[6]) {
			sum_sunshine -= price[6];
			return getSquash();
		}
	}
	else if (x == 60 && y == 28) {
		if (sum_sunshine >= price[7]) {
			sum_sunshine -= price[7];
			return getPotato();
		}
	}
	if (x == 0 && y == 29) {
		if (sum_sunshine >= price[8]) {
			sum_sunshine -= price[8];
			return getCherry();
		}
	}
	else if (x == 20 && y == 29) {
		if (sum_sunshine >= price[9]) {
			sum_sunshine -= price[9];
			return getPepper();
		}
	}
	else if (x == 40 && y == 29) {
		if (sum_sunshine >= price[10]) {
			sum_sunshine -= price[10];
			return getSun();
		}
	}
	return false;

}
