//Theo Andonyadis
//ECE 2620 Section 001
//Lab 6
#include <iostream>
#include <ctime>
#include "myheaders.h"
#include "dllist.h"
#include "intStack.h"
#include "intQueue.h"
using namespace std;
const int EMPTY_LIST = 1;
int main()
{
	int el;
	char choice;
	while(choice != 5) //While loop to run the menu repeatedly
	{
	cout << "Please select a number from the following options." << endl;
	cout << "(1) Create Simple (Unsorted) List" << endl;
	cout << "(2) Create Sorted List" << endl;
	cout << "(3) Create Queue (FIFO)" << endl;
	cout << "(4) Create Stack (LIFO)" << endl;
	cout << "(5) Exit" << endl;
	cin >> choice;
	switch(choice) { 	//switch menu with 5 cases
		case '1' :
		{
			intDLList list1;
			while(choice !=7)		//menu for unsorted list
			{
			cout << endl << "Please select a number from the following options" << endl;
			cout << "(1) Enter integer for insertion at head of list" << endl;
			cout << "(2) Enter integer for insertion at tail of list" << endl;
			cout << "(3) Display and delete integer from head of list" << endl;
			cout << "(4) Display and delete integer from tail of list" << endl;
			cout << "(5) Search for integer in list and delete that node" << endl;
			cout << "(6) Display contents of list from head to tail in order" << endl;
			cout << "(7) Exit" << endl;
			cin >> choice;
			switch(choice) {
				case '1':		//fn to add int to head
					cin >> el;
					list1.addToHead(el);
					break;
				case '2':		//fn to add int to tail
					cin >> el;
					list1.addToTail(el);
					break;
				case '3':		//fn to delete from head
					try {		//try-catch to ensure program doesn't crash if the list is empty
						int val=list1.deleteFromHead();
						cout << val << endl;
					} catch(int error_code)
						{
						cerr << "Error: " << error_code << ", the list is empty" << endl;
					}
					break;
				case '4':		//fn to delete from tail
					try {		//try-catch to ensure program doesn't crash if the list is empty
						int val=list1.deleteFromTail();
						cout << val << endl;
					} catch(int error_code)
						{
						cerr << "Error: " << error_code << ", the list is empty" << endl;
					}
					break;
				case '5':		//fn to search and delete integer
					cin >> el;
					list1.deleteNode(el);
					break;
				case '6':		//fn to print list
					list1.printList();
					break;
				case '7': // Exit Program

					cout << endl << "Received program exit command - I QUIT!" << endl << endl;

					return 0;

				default: // Error in selection

					cout << endl << "Incorrect selection, try again from the menu below." << endl;
					break;
			}
			}
			}
		case '2':
		{
			intDLList list2;
			while(choice !=4)		//menu for sorted list
			{
			cout << endl << "Please select a number from the following options" << endl;
			cout << "(1) Enter integer for sorted insertion (increasing order) into list" << endl;
			cout << "(2) Search and delete integer, if present in list" << endl;
			cout << "(3) Display contents of sorted list of integers (increasing order)" << endl;
			cout << "(4) Exit" << endl;
			cin >> choice;
			switch(choice) {
				case '1':		//fn to add integer in sorted order
					cin >> el;
					list2.addSorted(el);
					break;
				case '2':		//fn to search and delete integer
					cin >> el;
					list2.deleteNode(el);
					break;
				case '3':		//fn to print list in increasing order
					list2.printList();
					break;
				case '4': // Exit Program

					cout << endl << "Received program exit command - I QUIT!" << endl << endl;

					return 0;

				default: // Error in selection

					cout << endl << "Incorrect selection, try again from the menu below." << endl;
					break;
			}
			}
			}
		case '3':
		{
			intQueue queue;
			while(choice !=4)		//menu for queue
			{
			cout << endl << "Please select a number from the following options" << endl;
			cout << "(1) ENQUEUE" << endl;
			cout << "(2) DEQUEUE" << endl;
			cout << "(3) PRINT QUEUE" << endl;
			cout << "(4) Exit" << endl;
			cin >> choice;
			switch(choice) {
				case '1':		//fn to enqueue
					cin >> el;
					queue.enqueue(el);
					break;
				case '2':		//fn to dequeue
					queue.dequeue();
					break;
				case '3':		//fn to print queue
					queue.printQueue();
					break;
				case '4': // Exit Program

					cout << endl << "Received program exit command - I QUIT!" << endl << endl;

					return 0;

				default: // Error in selection

					cout << endl << "Incorrect selection, try again from the menu below." << endl;
					break;
			}
			}
			}
		case '4':
		{
			intStack stack;
			while(choice !=4)		//menu for stack
			{
			cout << endl << "Please select a number from the following options" << endl;
			cout << "(1) PUSH" << endl;
			cout << "(2) POP" << endl;
			cout << "(3) PRINT STACK" << endl;
			cout << "(4) Exit" << endl;
			cin >> choice;
			switch(choice) {
				case '1':		//fn to push
					cin >> el;
					stack.push(el);
					break;
				case '2':		//fn to pop
					stack.pop();
					break;
				case '3':		//fn to print stack
					stack.printStack();
					break;
				case '4': // Exit Program

					cout << endl << "Received program exit command - I QUIT!" << endl << endl;

					return 0;

				default: // Error in selection

					cout << endl << "Incorrect selection, try again from the menu below." << endl;
					break;
			}
			}
			}
		case '5': // Exit Program
		{

					cout << endl << "Received program exit command - I QUIT!" << endl << endl;

					return 0;
		}

		default: // Error in selection
		{

					cout << endl << "Incorrect selection, try again from the menu below." << endl;
		}
	}
	
	
	
	return 0;
}
}
