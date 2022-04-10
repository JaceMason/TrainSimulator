#ifndef _STATION_H_DEFINED_
#define _STATION_H_DEFINED_
#include "Train.h"
#include "Track.h"

class Station{
private:
	Track *arrivingTrack;
	Track *departingTrack;
	Train *currentTrain;

	string name;
	int index;
	string cargo;

	int checkTime;
	int checkTimer;

	int cargoLoadTime;
	int cargoTimer;

public:
	Station();
	Station(string name, int index, string cargo, Track *arrive, Track *depart);
	void tick();
	void send_off_train();
	bool check_logic();
	bool cargo_logic();
};

#endif
