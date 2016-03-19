#include "DList.hpp"

// The default constructor initializes all member variables.
DList::DList()
{
    mySize = 0;
}

// An overloaded constructor that assigns the values of a DList
// object to a new one.
DList::DList( const DList &source )
{
    // this = source;
}

// The destructor deletes all nodes in the linked list.
DList::~DList()
{
    // delete[] first;
}

// Default constructor for the nested class Node.
DList::Node::Node()
{
    data = 0;
    next = NULL;
}

// Overloaded constructor for nested class Node.
DList::Node::Node( ElementType initData )
{
    data = initData;
    next = NULL;
}

// DList.find() - Returns the index of a specific value in the linked list.
int DList::find( ElementType value ) const
{
    
}

// DList.empty() - Determine if the linked list is empty or not.
bool DList::empty() const
{
    
}

// DList.insert() - Inserts a new node into the linked list.
void DList::insert( ElementType dataVal, int index )
{
    NodePointer newNode;
    NodePointer current = first;
    
    // Insert node at end of linked list.
    while ( current != NULL )
    {
        current = current->next;
    }
    
    newNode->data = dataVal;
    current = newNode;
    
    mySize++;
}

// DList.erase() - Remove a node from the linked list.
void DList::erase( int index )
{
    
}

// DList.display() - Display each value in the linked list.
void DList::display( std::ostream &out ) const
{
    
}

// DList.getSize() - Returns the number of nodes currently held by the linked list.
int DList::getSize() const
{
    return mySize;
}

// Overloaded assignment operator.
const DList &DList::operator=( const DList &rightHandSide )
{
    
}
