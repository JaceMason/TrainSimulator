#include "Station.h"
#include <stdio.h>

Station::Station(){
	arrivingTrack = NULL;
	departingTrack = NULL;
	currentTrain = NULL;
	checkTime = 1;
	checkTimer = 0;
	cargoLoadTime = 1;
	cargoTimer = 0;
	cargo = "Sand";
	printf("Station stationed.\n");
}

Station::Station(string name, int index, string cargo, Track *arrive, Track *depart):
	Station()
{
	this->name = name;
	this->index = index;
	this->cargo = cargo;
	
	arrivingTrack = arrive;
	departingTrack = depart;
}

void Station::tick(){
	printf("Station Status:\n");
	//Try to get a Train
	if(currentTrain == NULL){
		currentTrain = arrivingTrack->receive_train(); //Might be set to NULL.
		if(currentTrain == NULL){
			printf("\tNo train stationed...\n");
		}
		else{
			printf("\tTrain just arrived!\n");
		}
	}

	//If we have a train.
	if(currentTrain != NULL){
		//cargo_logic() will only run if check_logic() is true
		if(check_logic() && cargo_logic()){
			send_off_train();
		}
	}
}

void Station::send_off_train(){
	printf("\tSending off train\n");
	departingTrack->send_train(currentTrain);
	currentTrain = NULL;
	checkTimer = 0;
	cargoTimer = 0;
}

bool Station::check_logic(){
	if(checkTimer >= checkTime){
		return true;
	}
	else{
		printf("\tChecking Train\n");
		checkTimer++;
		return false;
	}
}

bool Station::cargo_logic(){
	if(cargoTimer >= cargoLoadTime){
		currentTrain->load_cargo(cargo);
		return true;
	}
	else{
		printf("\tLoading %s\n", cargo.c_str());
		cargoTimer++;
		return false;
	}
}
