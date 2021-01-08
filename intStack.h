#ifndef _INTSTACK_H_
#define _INTSTACK_H_
#include "dllist.h"
class intStack		//class for stacks
{
public:		//member fns
	void push(int);
	int pop();
	void printStack();
private:		//object
	intDLList list3;

};

#endif // _INTSTACK_H_


