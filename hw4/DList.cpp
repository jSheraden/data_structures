#include "DList.hpp"

// The default constructor initializes all member variables.
DList::DList() : first( NULL )
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
    NodePointer current = first;
    
    while ( current != NULL )
    {
        delete[] current;
        current = current->next;
    }
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
    NodePointer current = first;
    
    for ( int i = 0; i < value; i++ )
    {
        current = current->next;
    }
    
    return current->data;
}

// DList.empty() - Determine if the linked list is empty or not.
bool DList::empty() const
{
    return first == NULL;
}

// DList.insert() - Inserts a new node into the linked list.
void DList::insert( ElementType dataVal, int index )
{
    NodePointer newNode = new Node(dataVal);
    
    // If first is null, the new node becomes the beginning
    // of the list.
    if ( empty() )
    {
        first = newNode;
    }
    
    // If first is not empty, add the new node to the end
    // of the list.
    else
    {
        NodePointer current = first;
        
        while ( current->next != NULL )
        {
            current = current->next;
        }
        
        current->next = newNode;
    }
    
    mySize++;   // Increment the size of the list by 1.
}

// DList.erase() - Remove a node from the linked list.
void DList::erase( int index )
{
    NodePointer current = first;
    
    // Loop through the list until one node before
    // the specified index.
    for ( int i = 0; i < index - 1; i++ )
    {
        current = current->next;
    }
    
    // If the node that comes after the one at the
    // specified index is not empty, that node takes
    // its place.
    if ( current->next->next != NULL )
    {
        delete[] current->next;
        current->next = current->next->next;
    }
    
    // If not, just delete the node at the specified index.
    else
    {
        delete[] current->next;
    }
    
    mySize--;   // Reduce the size of the list by 1.
}

// DList.display() - Display each value in the linked list.
void DList::display( std::ostream &out ) const
{
    NodePointer current = first;
    
    out << "List: ";
    
    while ( current != NULL )
    {
        out << current->data << " ";
        current = current->next;
    }
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
