#include "Train.h"
#include <stdio.h>
Train::Train(int speed){
	printf("Train trained.\n");
	position = 0;
	this->speed=speed;
	arrival = false;
	cargo = "";
}

void Train::tick(int trackDist){
	printf("Train tick... ");
	if(!arrival){
		position += speed;
		printf("Train on track moving to %d...\n", position);
		if(position >= trackDist){
			arrival = true;
			printf("Train arriving at a station!\n");
		}
	}
}

bool Train::arrived(){
	if(arrival){
		arrival = false;
		position = 0;
		return true;
	}
	else{
		return false;
	}
}

bool Train::load_cargo(string cargo){
	this->cargo = cargo;
}
