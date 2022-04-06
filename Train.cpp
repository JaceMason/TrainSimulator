#include "Train.h"
#include <stdio.h>
Train::Train(int speed){
	printf("Train trained.\n");
	position = 0;
	this->speed=speed;
}

void Train::tick(int trackDist){
	printf("Train tick\n");
	if(!arrival){
		position += speed;
		printf("Train on track moving to %d...\n", position);
		if(position >= trackDist){
			arrival = true;
			printf("Train arriving at a station!");
		}
	}
}
