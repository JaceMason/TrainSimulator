#ifndef _STATION_H_DEFINED_
#define _STATION_H_DEFINED_
#include "Train.h"
#include "Track.h"

class Station{
private:
	Track *arrivingTrack;
	Track *departingTrack;
	Train *currentTrain;
	int checkTime;
	int checkTimer;
	
public:
	Station();
	Station(Track *arrive, Track *depart);
	void tick();
	void send_off_train();
};

#endif
