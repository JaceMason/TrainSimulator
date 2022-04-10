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
	printf("%s Station (%d) Status:\n", name.c_str(), index);
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
	//If train is at the right destination, do the cargo logic.
	if(currentTrain->at_destination(index)){
		if(cargoTimer >= cargoLoadTime){
			if(currentTrain->peek_cargo() == ""){
				currentTrain->load_cargo(cargo);
				printf("\tTrain loaded with %s\n", cargo.c_str());
			}
			else{
				string stuff = currentTrain->unload_cargo();
				printf("\tGot %s from the train!\n", stuff.c_str());
			}
			return true;
		}
		else{
			printf("\tTrain's cargo is being processed...\n");
			cargoTimer++;
			return false;
		}
	}
	//Not destination, so no cargo logic.
	else{
		return true;
	}
}
