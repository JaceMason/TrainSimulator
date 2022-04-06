#include <stdio.h>
#include "Station.h"
#include "Train.h"
#include "Track.h"

int main(){
	Station station;
	Track track;
	Train train(10);
	track.send_train(&train);
	station.tick();
	track.tick();
	return 0;
	
}
