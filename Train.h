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
	
public:
	Train(int speed);
	void tick(int trackDist);
	bool arrived();
	bool load_cargo(string cargo);
};
#endif
