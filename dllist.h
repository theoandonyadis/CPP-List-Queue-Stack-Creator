#ifndef _DLLIST_H_
#define _DLLIST_H_
#include "int-dll-node.h"
class intDLList		//class for DLList functions
{
public:
	intDLList() {head=tail=nullptr;}		//constructor and destructor
	~intDLList();
	bool isEmpty() {return (head==nullptr);}		//fn declarations to operate on lists
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead();
	int deleteFromTail();
	void deleteNode(int);
	bool isInList(int) const;
	void addSorted(int);
	void printList();
private:
	intDLLNode *head, *tail;
};

#endif // _DLLIST_H_

