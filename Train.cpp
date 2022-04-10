#include "Train.h"
#include <stdio.h>
#include <stdlib.h>

Train::Train(int speed){
	printf("Train trained.\n");
	position = 0;
	this->speed=speed;
	arrival = false;
	cargo = "";
	destination = -1;
	lastDest = -1;
}

void Train::tick(int trackDist){
	printf("Train tick... ");
	if(!arrival){
		position += speed;
		printf("Train on track moving to %d... Heading to station %d\n", position, destination);
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

void Train::load_cargo(string cargo){
	this->cargo = cargo;
	cargoPeeks = 0;
	lastDest = destination;
	destination = -1;
}

string Train::unload_cargo(){
	string retCargo = cargo;
	cargo = "";
	cargoPeeks = 0;
	lastDest = destination;
	destination = -1;
	return retCargo;
}

string Train::peek_cargo(){
	cargoPeeks++;
	return cargo;
}

bool Train::at_destination(int stationIndex){
	if(stationIndex == destination){
		return true;
	}
	
	return false;
}

void Train::set_rand_dest_if_arrived(int stationAmount){
	if(destination == -1){
		do{
			//do while needed because if destination == -1 it will never be lastDest after first station
			destination = rand() % stationAmount;
		}while(destination == lastDest);
	}
}
