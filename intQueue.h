#ifndef _INTQUEUE_H_
#define _INTQUEUE_H_
#include "dllist.h"
class intQueue		//class for queues
{
public:		//member fns
	void enqueue(int);
	int dequeue();
	void printQueue();
private:		//object
	intDLList list4;
};

#endif // _INTQUEUE_H_

