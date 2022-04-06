#ifndef _TRAIN_H_DEFINED_
#define _TRAIN_H_DEFINED_

class Train{
private:
	int speed;
	int position;
	bool arrival;
public:
	Train(int speed);
	void tick(int trackDist);
	bool arrived();
};
#endif
