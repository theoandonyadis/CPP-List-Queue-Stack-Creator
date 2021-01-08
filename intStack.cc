#include "intStack.h"
#include "dllist.h"
#include <iostream>
#include <ctime>
using namespace std;
void intStack::push(int el) {		//push fn adds to head
	list3.addToHead(el);
}
int intStack::pop() {		//pop fn deletes from tail and prints val
	int val = list3.deleteFromHead();		
	cout << val;
	return val;
}
void intStack::printStack() {		//prints stack
	list3.printList();
}

