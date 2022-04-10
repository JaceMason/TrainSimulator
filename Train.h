#ifndef _TRAIN_H_DEFINED_
#define _TRAIN_H_DEFINED_
#include <string>
using std::string;

class Train{
private:
	int speed;
	int position;
	bool arrival;
	string cargo;
	int destination;
	int lastDest;
	int cargoPeeks;
	
public:
	Train(int speed);
	void tick(int trackDist);
	bool arrived();

	void load_cargo(string cargo);
	string unload_cargo();
	string peek_cargo();
	
	bool at_destination(int stationIndex);
	void set_rand_dest_if_arrived(int stationAmount);
};
#endif
