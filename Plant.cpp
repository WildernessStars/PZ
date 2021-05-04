#include"Plant.h"
//extern int sum_sunshine;

int Sunflower::effect(){
	if (is_alive) {
		//sum_sunshine += 50;
		return 1;
	}
	return 0;
}
