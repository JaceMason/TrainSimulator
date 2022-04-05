#include "Train.h"
#include <stdio.h>
Train::Train(int speed){
	printf("Train trained.\n");
	position = 0;
	this->speed=speed;
}

void Train::tick(){
	position += speed;
	printf("Train on track moving to %d...\n", position);
}
