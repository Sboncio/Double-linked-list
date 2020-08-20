/**
*\class linklist
* \brief The class that will control the double linked list.

* \param m_Front Pointer to the front of the list
* \param m_Back Pointer to the back of the list
* \param m_Current Pointer that can traverse the list and retrieve data from any node
* \param m_size Integer that keeps track of the lists size
*/


#ifndef LINKLIST_H
#define LINKLIST_H

#include <memory>
#include <string>
#include <stdlib.h>
#include <iostream>

#include "ListNode.h"

using namespace std;

template<class G>
class linklist {
private:
	listnode<G>* m_Front;  
	listnode<G>* m_Back; 
	listnode<G>* m_Current; 

	unsigned int ui_size; 

public:
	linklist<G>();


	void pushFront(G NewData);
	void pushBack(G NewData);

	void PushBeforeCurrent(G NewData);
	void PushAfterCurrent(G NewData);

	G popBeforeCurrent();
	G popAfterCurrent();

	G popFront();
	G popBack();

	G getData();
	G getFrontNode();
	G getBackNode();

	string emptyList();

	bool empty();

	int listSize();

	void moveForward();
	void moveBackward();

	void ListAll();
};


/*!
\fn linklist<G>::linklist()
This function is the constructor of the linklist class
*/

template<class G>
linklist<G>::linklist()
{
	m_Front = nullptr; //!< Set the front of the list to null
	m_Back = nullptr; //!< Set the back of the list to null
	m_Current = nullptr; //!< Set the currently selected node to null

}



/*!
\fn void linklist<G>::pushFront(G NewData)
Pushes and item to the front of the list

\param NewData The data that will be added to the list node
*/

template<class G>
void linklist<G>::pushFront(G NewData)
{

	if (empty()) { //!< Check if list is empty 
		m_Front = new listnode<G>(NewData); //!< Set the new node to the front

		m_Back = m_Front; //!< Set the back to the same as front
		m_Current = m_Front; //!< Set the current to the same as front
	}
	else {
		listnode<G> * tempFront = m_Front; //!< Make a temporary front pointer
		m_Front = new listnode<G>(NewData); //!< Make a new node at the front
		m_Front->setBackward(tempFront); //!< Connect the new front to the old front
		tempFront->setForward(m_Front); //!< Connect the old front to the new front

	}
	ui_size++; //!< Increment the size
}


/*!
\fn void linklist<G>::pushBack(G NewData)
Pushes an item to the back of the list

\param NewData The data that will be added to the list node
*/
template<class G>
void linklist<G>::pushBack(G NewData)
{
	if (empty()) { //!< Check if the list is empty
		m_Back = new listnode<G>(NewData); //!<Assign new node to the back of the list
		m_Front = m_Back; //!< Make the front the same as the back
		m_Current = m_Back; //!< Make the current the same as the back
	}
	else {
		listnode<G> * tempBack = m_Back;  //!< Make a new pointer to the back of the list
		m_Back = new listnode<G>(NewData); //!< Make a new node at the end of the list
		tempBack->setBackward(m_Back); //!< Connect the old and new back
		m_Back->setForward(tempBack); //!< Connect the old and new back

	}
	ui_size++; //!< Increment the size
}



/*!
\fn void linklist<G>::PushBeforeCurrent(G NewData)
Push the new node in front of the currently selected node

\param NewData The data that will be added to the list node
*/

template <class G>
void linklist<G>::PushBeforeCurrent(G NewData)
{

	if (!empty() && (m_Current != m_Front)) { //!< Check if the node is empty and isn't at the front
		listnode<G> * tempForward = m_Current->getForward(); //!< Make a temporary forward pointer
		listnode<G> * tempBackward = m_Current; //!< Make a temporary backward pointer
		m_Current = new listnode<G>(NewData); //!< Make a new node and make 'Current' point at it
		m_Current->setBackward(tempBackward); //!< Connect the new node to the node behind
		m_Current->setForward(tempForward); //!< Connect the new node to the node in front

		tempForward->setBackward(m_Current); //!< Connect the node in front to the new node
		tempBackward->setForward(m_Current); //!< Connect the node behind to the new node
		ui_size++; //!< Increment the size
	}

}



/*!
\fn void linklist<G>::PushAfterCurrent(G NewData)
Function to push a new node behind the currently selected node

\param NewData The data that will be added to the list node
*/

template <class G>
void linklist<G>::PushAfterCurrent(G NewData)
{
	if (!empty() && (m_Current != m_Back)) { //!< Check if the node is empty and isn't at the front

		listnode<G> * tempForward = m_Current; //!< Make a temporary forward pointer
		listnode<G> * tempBackward = m_Current->getBackward(); //!< Make a temporary backward pointer
		m_Current = new listnode<G>(NewData); //!< Make a new node and make 'Current' point at it

		m_Current->setBackward(tempBackward);  //!< Connect the new node to the node behind
		m_Current->setForward(tempForward); //!< Connect the new node to the node in front

		tempForward->setBackward(m_Current); //!< Connect the node in front to the new node
		tempBackward->setForward(m_Current); //!< Connect the node behind to the new node
		ui_size++; //!< Increment the size

	}
}



/*!
\fn G linklist<G>::popFront()
Function to remove the item from the front of the list.

*/

template<class G>
G linklist<G>::popFront()
{

	if (ui_size > 1) { //!< Check if there is more than one item in the list
		listnode<G> * tempFront = m_Front; //!< Make a temporary front pointer
		m_Front = m_Front->getBackward(); //!< Assign the front to a different node

		m_Front->setForwardNull(); //!< Ensure that the forward pointer of the front is null
		tempFront->setBackwardNull(); //!< Ensure that the backward pointer of the old front is null
		string result = tempFront->getData(); //!< Extract the data from the old front
		delete tempFront; //!< Delete the old front
		ui_size--; //!< Reduce the size by 1
		return result; //!< Return the data from the removed node
	}
	else if (ui_size == 1) { //!< Check if size is equal to 1
		string result = m_Front->getData(); //!< Get the data from the node
		delete m_Front; //!< Delete the node
		m_Front = nullptr; //!< Set the Front pointer to null
		m_Back = nullptr; //!< Set the back pointer to null
		m_Current = nullptr; //!< Set the current pointer to null
		ui_size--; //!< Reduce the size by 1
		return result; //!< Return the data from the removed code
	}
	else {
		return "No nodes left"; //!< If list's empty, say there are no nodes
	}
}




/*!
\fn G linklist<G>::popBack()
The function to remove a node from the back of the list


*/

template<class G>
G linklist<G>::popBack()
{

	if (ui_size > 1) { //!< Check if there is more than one item in the list
		listnode<G> * tempBack = m_Back; //!< Set a temporary back pointer
		m_Back = m_Back->getForward(); //!< Set the Back pointer to the item that will be at the back

		m_Back->setBackwardNull(); //!< Make the new back point at nothing behind
		tempBack->setForwardNull(); //!< Make the old back point at nothing
		string result = tempBack->getData(); //!< Extract the data from the old back
		delete tempBack; //!< Delete the old back
		ui_size--; //!< Reduce the size by 1
		return result; //!< Return the data from the removed node
	}
	else if (ui_size == 1) { //!< Check if size is equal to 1
		string result = m_Back->getData();  //!< Get the data from the node that's to be removed
		delete m_Back; //!< Delete the back node
		m_Back = nullptr; //!< Set the Back pointer to null
		m_Front = nullptr; //!< Set the front pointer to null
		m_Current = nullptr; //!< Set the 'Current' pointer to null
		ui_size--; //!< Reduce the size by 1
		return result; //!< Return the result from the removed node
	}

}


/*!
\fn G linklist<G>::popBeforeCurrent()
Function that will remove the node before the currently selected node
\param ToDelete A pointer to the node that will be deleted
*/

template <class G>
G linklist<G>::popBeforeCurrent()
{
	if (m_Current->getForward() != nullptr) { //!< Check if the currently selected node is at the front

		listnode<G> * ToDelete = m_Current->getForward(); //!< Make a new pointer to the node that will be deleted 

		if (ToDelete->getForward() != nullptr) { //!< Check that the pointer to be deleted will not be at the front
			m_Current->setForward(ToDelete->getForward()); //!< Make the current node skip the node that's to be deleted
			ToDelete->setBackwardNull(); //!< Make the node to be deleted point at nothing behind
			ToDelete->setForwardNull(); //!< Make the node to be deleted point at nothing in front
			
			listnode<G> * tempForward = m_Current->getForward(); //!< Make a pointer to a node in front of the node that will be defeated
			tempForward->setBackward(m_Current); //!< Make that node skip the node that will be deleted. 

			string result = ToDelete->getData(); //!< Get the data from the node that will be deleted
			delete ToDelete; //!< Delete the node
			ui_size--; //!< Reduce the size by 1
			return result; //Return the data from the deleted node

		}
		else { //!< If the node to be deleted is at the front
			string result = popFront(); //Get the data from the node and use the popFront function
			ui_size--; //!< Reduce the size by 1
			return result; //!< Return the data from the deleted node
		}
		
	}
}


/*!
\fn G linklist<G>::popAfterCurrent()
Function to remove a node after the currently selected node

\param ToDelete A pointer to the node that will be deleted
*/

template <class G>
G linklist<G>::popAfterCurrent()
{
	if (m_Current->getBackward() != nullptr) {

		listnode<G> * ToDelete = m_Current->getBackward();

		if (ToDelete->getBackward() != nullptr) {
			m_Current->setBackward(ToDelete->getBackward());
			ToDelete->setBackwardNull();
			ToDelete->setForwardNull();

			listnode<G> * tempBackward = m_Current->getBackward();
			tempBackward->setForward(m_Current);

			string result = ToDelete->getData();
			delete ToDelete;
			ui_size--;
			return result;
		}
		else {
			string result = popBack();
			ui_size--;
			return result;
		}

	}
}

/*!
\fn G linklist<G>::getData()
Function that retrieves the data from the currently selected node
*/

template<class G>
G linklist<G>::getData()
{
	return m_Current->getData(); //!< Uses the 'getData' function from the listnode class to retrieve the data
}




/*!
\fn G linklist<G>::getFrontNode()
Function to retrieve the data from the node at the front of the list
*/
template <class G>
G linklist<G>::getFrontNode()
{
	return m_Front->getData(); //!< Uses the 'getData' function from the listnode class to retrieve the data from the front node
}

/*!
\fn G linklist<G>::getBackNode()
Function to retrieve the data from the back of the list
*/

template <class G>
G linklist<G>::getBackNode()
{
	return m_Back->getData(); //!< Uses the 'getData' function from the listnode class to retrieve the data from the back node
}


/*!
\fn string linklist<G>::emptyList()
Function that will retrieve the size of the list, and return a string that says if it's empty or not
*/

template <class G>
string linklist<G>::emptyList() {
	if (empty()) { //!< Check if the list is empty
		return "The list is empty";
	}
	else {
		return "The list isn't empty";
	}
}



/*!
\fn bool linklist<G>::empty()
Will say if the list is currently empty
*/

template<class G>
bool linklist<G>::empty() 
{
	return ui_size == 0; //!< Returns true if the list is empty
}


/*!
\fn int linklist<G>::listSize()
Function to return the size of the list
*/

template <class G>
int linklist<G>::listSize() {
	return ui_size; //!< Returns the integer size variable
}



/*!
\fn void linklist<G>::moveForward()
Function that will make the 'Current' pointer traverse forward
*/

template<class G>
void linklist<G>::moveForward() {
	if (m_Current != m_Front) { //!< Check to ensure that 'Current' isn't the same as the front node
		m_Current = m_Current->getForward(); //!< Move the 'Current' pointer forwards
		
	}
}

/*!
\fn void linklist<G>::moveBackward()
Function to make the 'Current' pointer traverse backwards 
*/

template <class G>
void linklist<G>::moveBackward()
{
	if (m_Current != m_Back) { //!< Check to ensure that 'Current' isn't at the back
		m_Current = m_Current->getBackward(); //!< Move the 'Current' pointer backwards
		
	}
}

/*!
\fn void linklist<G>::ListAll()
Function to list all items in the list
*/

template <class G>
void linklist<G>::ListAll()
{
	m_Current = m_Front; //!< Make the 'Current' pointer point at the front node

	while (m_Current != m_Back) //!< While the 'Current' pointer isn't pointing at the back node
	{
		cout << m_Current->getData() << endl; //!< Extract the data from the node and output it
		m_Current = m_Current->getBackward(); //!< Move the 'Current' pointer backwards
	}

	m_Current = m_Back; //!< Set the 'Current' pointer to the back node
	cout << m_Current->getData() << endl; //!< Output the back node's data
	m_Current = m_Front; //!< Set the 'Current' pointer to the front

	
}



#endif
