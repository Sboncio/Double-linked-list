/**
@file main.cpp
*/


/*! \mainpage Lab Book 3
 *
 * Implementation of a Double Linked List
 */

// Define and includes to show memory leak report
#define _CRTDBG_MAP_ALLOC  

#include "LinkList.h"

#include <iostream>
using namespace std;


int main() /** Entry point for the application */
{
	linklist<string> Mylist; //!< Creating the linklist object

	//! Pushing five items to the front of the list
	cout << "Pushing five items to the front\n";
	Mylist.pushFront("I'm Sam");
	Mylist.pushFront("World");
	Mylist.pushFront("Hello");
	Mylist.pushFront("Siwmae");
	Mylist.pushFront("sut wyt ti");


	//! Pushing six items to the back of the list
	cout << "Pushing six items to back\n";
	Mylist.pushBack("This is");
	Mylist.pushBack("A double");
	Mylist.pushBack("Link list");
	Mylist.pushBack("Hyn yn");
	Mylist.pushBack("list dau");
	Mylist.pushBack("dolen.");

	
	//!Displaying all the items that are held in the list
	cout << "Listing all the items: \n";
	Mylist.ListAll();

	
	//! Displaying the size of the list and a text description of if the list is full or not
	cout << endl << "There are " << Mylist.listSize() << " nodes in the list so " << Mylist.emptyList() << endl << endl << endl;

	//!Traversing the list backwards and forwards
	cout << "Moving backwards on the list\n";
	cout << "Before movement: " << Mylist.getData();
	Mylist.moveBackward();
	cout << "\nAfter movement: " << Mylist.getData() << endl;

	cout << "Moving forward on the list\n";
	cout << "Before movement: " << Mylist.getData();
	Mylist.moveForward();
	cout << "\nAfter movement: " << Mylist.getData();


	//! Traversing the list backwards several times
	cout << endl << "Move backward in the list six times:\n";

	for (int i = 0; i < 6; i++) {
		Mylist.moveBackward();
	}

	//! Displaying the front and back nodes, whjile the current pointer is in the middle of the list
	cout << endl << "Front node contains: " << Mylist.getFrontNode() << ".			Back node contains: " << Mylist.getBackNode() << endl;

	//!Displaying a node in the middle of the list
	cout << "current node is :" << Mylist.getData() << endl;
	
	//! Pushing a node before the current node
	cout << "Adding node before current\n";
	Mylist.PushBeforeCurrent("Bonjour");

	//! Pushing a node after the currently selected node
	cout << "\nAdding node after current\n ";
	Mylist.PushAfterCurrent("Helo");

	cout << endl << endl;

	//! Listing all nodes after these changes have been made
	Mylist.ListAll();

	for (int i = 0; i < 6; i++) {
		Mylist.moveBackward();
	}

	//! Popping an item from the front
	cout << endl << "Popping from front: " << Mylist.popFront();

	//! Popping an item from the back
	cout << endl << "Popping from Back: " << Mylist.popBack();

	Mylist.moveBackward();


	//!Popping an item before the currently selected node
	cout << endl << "Popping before current: " << Mylist.popBeforeCurrent() << endl;

	//! Popping an item after the currently selected node
	cout << endl << "Popping after current: " << Mylist.popAfterCurrent() << endl;

	//! Listing everything once again
	cout << endl << endl << "Listing current list:\n";
	Mylist.ListAll();


	//! Clearing the list completely
	cout << "Clearing the list\n";
	while (!Mylist.empty()) {
		Mylist.popFront();
	}

	//! checking that the list is empty
	cout << Mylist.emptyList() << endl;
	cout << "There are " << Mylist.listSize() << " elements is the list\n\n\n";

	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
}
