#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using std::string;
using namespace std::chrono;
using std::vector;

#include "Station.h"
#include "Train.h"
#include "Track.h"

#define STATIONNUM 3
#define TRAINNUM 1

int main(){
	srand (time(NULL));
	string stationNames[] = {"Orange", "Purple", "Green", "Amber"};
	string stationCargo[] = {"Stones", "Plants", "Trash", "Books"};
	Track tracks[STATIONNUM];
	vector <Station> stations;
	Train trains[TRAINNUM] = {Train(10)};

	//create and setup the stations
	stations.reserve(STATIONNUM);
	for(int i = 0, j = 1; i < STATIONNUM; i++, j++){
		if(j == STATIONNUM){
			j = 0;
		}
		stations.emplace_back(stationNames[i], i, stationCargo[i], &tracks[i], &tracks[j]);
	}
	tracks[0].send_train(&trains[0]);
	int hours = 1;
	while(1){
		auto start = high_resolution_clock::now();
		
		//Main Loop
		printf("\n-----Hour %d-----\n", hours);

		for(int i = 0; i < TRAINNUM; i++){
			trains[i].set_rand_dest_if_arrived(STATIONNUM);
		}
		
		for(int i = 0; i < STATIONNUM; i++){
			tracks[i].tick();
		}
		printf("\n");
		for(int i = 0; i < STATIONNUM; i++){
			stations[i].tick();
		}

		hours++;
		//End Main Loop
		
		auto diff = duration_cast<milliseconds>(high_resolution_clock::now()-start).count();
		std::this_thread::sleep_for(milliseconds(1000-diff));
	}
	return 0;
	
}
