#ifndef _TRAIN_H_DEFINED_
#define _TRAIN_H_DEFINED_

class Train{
private:
	int speed;
	int position;
public:
	Train(int speed);
	void tick();
};
#endif
