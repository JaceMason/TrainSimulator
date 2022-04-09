#include "Station.h"
#include <stdio.h>

Station::Station(){
	arrivingTrack = NULL;
	departingTrack = NULL;
	currentTrain = NULL;
	checkTime = 1;
	checkTimer = 0;
	printf("Station stationed.\n");
}

Station::Station(Track *arrive, Track *depart):
	Station()
{
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
		if(checkTimer >= checkTime){
			send_off_train();
		}
		else{
			printf("\tChecking Train\n");
			checkTimer++;
		}
	}
}

void Station::send_off_train(){
	printf("\tSending off train\n");
	departingTrack->send_train(currentTrain);
	currentTrain = NULL;
	checkTimer = 0;
}
