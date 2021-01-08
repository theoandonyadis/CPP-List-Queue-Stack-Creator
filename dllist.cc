#include "dllist.h"
#include <iostream>
#include <ctime>
using namespace std;
const int EMPTY_LIST = 1;
intDLList::~intDLList() {		//DLL destructor
	for(intDLLNode *p; !isEmpty(); head=p) {
		p=head->next;
		delete head;
	}
}
void intDLList::addSorted(int el) {		//fn to add integer el in sorted order in list
	if(isEmpty()) head=tail=new intDLLNode(el);		//if list is empty
	else {	
		if(head==tail) {		//if list has 1 node
			if(head->info < el) tail=head->next = new intDLLNode(el,nullptr,head);		//creates node for el before or after existing node
			else {
				head=head->prev = new intDLLNode(el,head,nullptr);
			}
				
		}
		else {		//if list has >1 node
			intDLLNode *tmp = head;
			while(tmp!=nullptr){
				if(tmp->info < el) tmp=tmp->next;		//advances tmp if less than el
				else {
					tmp->prev = new intDLLNode(el,tmp,tmp->prev);		//creates new node for el behind tmp
					if(tmp->prev->prev != nullptr) tmp->prev->prev->next = tmp->prev;		//sets next pointer behind new node to new node
					else {
						head = tmp->prev;		//sets head to new node if it was added at head
					}
					return;
					}
			}
			tail->next = new intDLLNode(el,nullptr,tail);		//if el is the greatest value, add after tail
		}
	}
}
void intDLList::printList() {		//fn to print list
	intDLLNode *tmp = head;
	for(tmp=head; tmp!=nullptr; tmp=tmp->next) {		//for loop to traverse with tmp and print it
		cout << tmp->info << " ";
	}
}
void intDLList::addToHead(int el) {		//fn to add to head
	if(head != nullptr) {		//if not empty
		head->prev = new intDLLNode(el,head,nullptr);		//add node to head and set pointers
		head=head->prev;
	}
	else head = tail = new intDLLNode(el);		//else node = head and tail
}
void intDLList::addToTail(int el) {		//fn to add to tail
	if(tail != nullptr) {		//if not empty
		tail->next = new intDLLNode(el,nullptr,tail);		//add node to tail and set pointers
		tail = tail->next;
	}
	else head = tail = new intDLLNode(el);		//else node = head and tail
}
int intDLList::deleteFromHead() {		//fn to delete from head
	if(!isEmpty()) {		//if empty, throw EMPTY_LIST
		int el = head->info;
		intDLLNode *tmp = head;
		if(head==tail)		//if 1 node, set to nullptr
			head=tail=nullptr;
		else {		//if >1 node, move head to next and delete previous head
			head = head->next;		
			head->prev = nullptr;
			delete tmp;
		}
		return (el);		//return el for display
	}
	else throw(EMPTY_LIST);
}
int intDLList::deleteFromTail() {		//fn to delete from head
	if(!isEmpty()) {		//if empty, throw EMPTY_LIST
		int el = tail->info;
		intDLLNode *tmp = tail;
		if(head==tail) {		//if 1 node, set to nullptr
			delete tail;
			head=tail=nullptr;
		}
		else {		//if >1 node, move tail to prev and delete previous tail
			tail = tail->prev;
			tail->next = nullptr;
			delete tmp;
		}
		return (el);		//return el for display
	}
	else throw(EMPTY_LIST);
}
bool intDLList::isInList(int el) const {		//fn to check if el is in list
	intDLLNode *tmp;
	for(tmp=head; tmp!=nullptr && tmp->info!=el; tmp=tmp->next);		//traverse list, until tmp = el
	return(tmp!=nullptr);
}
void intDLList::deleteNode(int el) {		//fn to search and delete node el
	if (head != nullptr)		//if not empty
		if (head==tail && el==head->info) { 		//if el is in list with 1 node, delete
			delete head;
			head = tail = nullptr;
		}
	else {
		if (el == head->info) {			//if el is in head, move head and delete
			intDLLNode *tmp = head;
			head = head->next;
			delete tmp;
		}
		else {
			intDLLNode *pred, *tmp;
			for(pred=head, tmp=head->next; tmp!=nullptr && tmp->info!=el;		//traverse list with 2 pointers, delete tmp, use pred to maintain next & prev
			    pred=pred->next, tmp=tmp->next);
			if(tmp!=nullptr) {
				pred->next = tmp->next;
				pred->prev = tmp->prev;
				if(tmp==tail) tail=pred;
				delete tmp;
			}
		}
	}
}




