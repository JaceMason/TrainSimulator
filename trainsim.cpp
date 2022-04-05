#include <stdio.h>
#include "Station.h"
#include "Train.h"
#include "Track.h"

int main(){
	Station station;
	Track track;
	Train train(10);
	
	station.tick();
	track.tick();
	train.tick();
	
	return 0;
	
}
