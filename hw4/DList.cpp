#include "DList.hpp"

// The default constructor initializes all member variables.
DList::DList() : first( NULL )
{
    mySize = 0;
}

// An overloaded constructor that assigns the values of a DList
// object to a new one.
DList::DList( const DList &source ) : first( NULL )
{
    mySize = 0;
    NodePointer current = source.first;
    
    for ( int i = 0; current != NULL; i++ )
    {
        insert( current->data, i );
        current = current->next;
    }
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
    data = "";
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
    
    for ( int i = 0; current != NULL; i++ )
    {
        if ( current->data == value )
        {
            return i;
        }
        else
        {
            current = current->next;
        }
    }
    
    return -1;
}

// DList.empty() - Determine if the linked list is empty or not.
bool DList::empty() const
{
    return first == NULL;
}

// DList.insert() - Inserts a new node into the linked list.
void DList::insert( ElementType dataVal, int index )
{
    NodePointer newNode = new Node( dataVal );
    
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
    
    if ( index < 0 || index > mySize )
    {
        std::cout << "Node not found in the list." << std::endl;
    }
    else if ( index == 0 )
    {
        first = first->next;
    }
    else
    {
        for ( int i = 0; i < index - 1; i++ )
        {
            current = current->next;
        }
        
        current->next = current->next->next;
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

// DList.getSize() - Returns the number of nodes currently in the linked list.
int DList::getSize() const
{
    return mySize;
}

// Overloaded assignment operator.
const DList &DList::operator=( const DList &rightHandSide )
{
    NodePointer current = rightHandSide.first;

    if ( this == &rightHandSide )
    {
        return *this;
    }
    
    for ( int i = 0; current != NULL; i++ )
    {
        insert( current->data, i );
        current = current->next;
    }
    
    return *this;
}
