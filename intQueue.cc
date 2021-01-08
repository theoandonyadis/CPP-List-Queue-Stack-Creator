#include "intQueue.h"
#include "dllist.h"
#include <iostream>
#include <ctime>
using namespace std;
void intQueue::enqueue(int el) {		//enqueue fn adds to tail
	list4.addToTail(el);
}
int intQueue::dequeue() {		//dequeue fn deletes from head and prints val
	int val = list4.deleteFromHead();
	cout << val;
	return val;
}
void intQueue::printQueue() {		//print fn
	list4.printList();
}



