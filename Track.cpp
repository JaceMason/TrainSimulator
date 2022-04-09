#include <stdio.h>
#include "Track.h"

Track::Track(){
	printf("Seems like we are on track.\n");
	
	onTrackList = NULL;
	arrivalList = NULL;
	trackDistance = 40;
}

Track::~Track(){
	Node *nextNode;
	while(arrivalList != NULL){
		nextNode = arrivalList->next;
		delete arrivalList; //No need to worry about content (stored elsewhere)
		arrivalList = nextNode;
	}
	
   	while(onTrackList != NULL){
		nextNode = onTrackList->next;
		delete onTrackList; //No need to worry about content (stored elsewhere)
		onTrackList = nextNode;
	}
}

void Track::tick(){
	printf("Track Status:\n");
	Node *currNode = onTrackList;
	while(currNode != NULL){
		printf("\t");
		currNode->train->tick(trackDistance);
		if(currNode->train->arrived()){
			add_train_to_list(&arrivalList, pop_train_from_list(&onTrackList));
		}
		currNode = currNode->next;
	}
}

void Track::send_train(Train *train){
	add_train_to_list(&onTrackList, train);
}

Train* Track::receive_train(){
	return(pop_train_from_list(&arrivalList));
}

void Track::add_train_to_list(Node **list, Train *train){
	Node *newNode = new Node(); //default node constructor (all 0)
	newNode->train = train;
	if(*list == NULL){
		*list = newNode;
	}
	else{
		Node *currNode = *list;
		while(currNode->next != NULL){
			currNode = currNode->next;
		}
		//Once above loop is done we currNode is the last element
		currNode->next = newNode;
	}
	
}

Train* Track::pop_train_from_list(Node **list){
	Train *retTrain = NULL;

	if(*list != NULL){
		retTrain = (*list)->train;

		//Cleanup
		Node *oldNode = *list;
		*list = (*list)->next;
		delete oldNode;
	}
	
	return retTrain;
}
