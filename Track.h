#ifndef _TRACK_H_DEFINED
#define _TRACK_H_DEFINED
#include "Train.h"

class Track{
private:
	struct Node{
		Train *train;
		Node *next;
	};
	
	Node *onTrackList;//Trains that will be checked for crashes.
	Node *arrivalList;//Trains waiting safely at the station.

	int trackDistance;
	
	void add_train_to_list(Node **list, Train *train);
	Train* pop_train_from_list(Node **list);
		
public:

	Track();
   	~Track();
	
	void tick();

	void send_train(Train *train);//Send the train to the next station
	Train* receive_train();//Get the trains that have arrived
};

#endif
