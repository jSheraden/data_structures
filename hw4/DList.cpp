#include "DList.hpp"

// The default constructor initializes all member variables.
DList::DList()
{
    first = new Node;
    mySize = 0;
}

// An overloaded constructor that assigns the values of a DList
// object to a new one.
DList::DList( const DList &source )
{
    this = source;
}

// The destructor deletes all nodes in the linked list.
DList::~DList()
{
    delete[] first;
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


// DList.getSize() - Returns the number of nodes currently held by the linked list.
int DList::getSize() const
{
    return mySize;
}
