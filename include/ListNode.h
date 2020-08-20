#ifndef LISTNODE_H
#define LISTNODE_H

/**!
*\class listnode This class defines the individual nodes that will be used in the link list
*
* \brief The list node class controls the nodes that are going to be used as different containers in the link list 
* 
* \param m_Data The data that will be held in each individual module
* \param m_Forward The pointer to the node in front of this current node (Default is nullptr)
* \param m_Backward The pointer the the node behind this current node (Default is nullptr)
*/

#include <string>
#include <memory>

template<class G>
class listnode {
private:
	G m_Data; //! Data to be held in the node

	listnode<G> * m_Forward; //! Node in front of this Node
	listnode<G> * m_Backward; //! Node behind the current Node

public:
	listnode(G newData);

	void setForward(listnode<G> * newFront);
	void setBackward(listnode<G> * newBack);

	void setForwardNull();
	void setBackwardNull();

	listnode<G> * getForward();
	listnode<G> * getBackward();

	G getData();

};

/*!
\fn listnode<G>::listnode(G newData)
Constructor for the list node. Will add the data to be stored in the node.
The 'Forward' and 'Backward' pointers are set to nullptr;
*/

template<class G>
listnode<G>::listnode(G newData) 
{
	m_Data = newData; //! Add the new data to the templated data variable

	m_Forward = nullptr; //! Node points to nothing in front
	m_Backward = nullptr; //! Node points to nothing behind
}

/*!
\fn void listnode<G>::setForward(listnode<G> * newFront) 
Function that will change the 'Forward' pointer to point at something in front of it
*/

template<class G>
void listnode<G>::setForward(listnode<G> * newFront) 
{
		m_Forward = newFront; //! Set the new 'Forward' pointer destination
}


/*!
\fn void listnode<G>::setForwardNull()
Function that sets the 'Forward' pointer to nullptr
*/
template <class G>
void listnode<G>::setForwardNull()
{
	m_Forward = nullptr; //! Forward is going to now equal nullptr
}


/*!
\fn void listnode<G>::setBackwardNull()
Function to set the 'Backward' pointer to nullptr
*/
template <class G>
void listnode<G>::setBackwardNull()
{
	m_Backward = nullptr; //! 'Backward' pointer is going to now equal nullptr
}

/*!
\fn void listnode<G>::setBackward(listnode<G> * newBack) 
Function to make the node point at an object behind it in the list
*/
template<class G>
void listnode<G>::setBackward(listnode<G> * newBack) 
{
	m_Backward = newBack; //! Set the 'Backward' pointer direction	
}

/*!
\fn listnode<G>  * listnode<G>::getForward()
Function to retrieve the node in front of the current node
*/

template<class G>
listnode<G>  * listnode<G>::getForward()
{
	return m_Forward; //! Returns the item the Forward pointer is pointing at
}


/*!
\fn listnode<G> * listnode<G>::getBackward()
Function to retrieve the node behind the current node
*/
template<class G>
listnode<G> * listnode<G>::getBackward()
{
	return m_Backward; //! Returns the item that the Backward pointer is pointing at
}


/*!
\fn G listnode<G>::getData()
Function to retrieve the data from the selected node.
*/
template<class G>
G listnode<G>::getData()
{
	return m_Data;
}

#endif
