#include <stdio.h>
#include <chrono>
#include <thread>

#include "Station.h"
#include "Train.h"
#include "Track.h"

using namespace std::chrono;

int main(){
	Station station;
	Track track;
	Train train(10);
	track.send_train(&train);
	while(1){
		auto start = high_resolution_clock::now();
		
		//Main Loop
		station.tick();
		track.tick();
		if(track.receive_train()){
			printf("Woo! The train is here!\n");
		}
		printf("\n");
		//End Main Loop
		
		auto diff = duration_cast<milliseconds>(high_resolution_clock::now()-start).count();
		std::this_thread::sleep_for(milliseconds(1000-diff));
	}
	return 0;
	
}
