#include "DList.hpp"

// Default constructor.
DList::DList() : mySize( 0 ), myCapacity( 0 )
{
    std::cout << "Testing..." << std::endl;
}

// Overloaded constructor.
DList::DList( int maxSize ) : mySize( 0 ), myCapacity( maxSize )
{
    
}

// DList.empty() - Empty the dynamic array.
bool DList::empty() const
{
    
}

// DList.insert() - Insert an element into the dynamic array.
void DList::insert( ElementType item, int pos )
{
    
}

// DList.erase() - Remove an element from the dynamic array.
void DList::erase( int pos )
{
    
}

// DList.display() - Display the dynamic array.
void DList::display( std::ostream &out ) const
{
    
}

// DList.getSize() - Get the current size of the dynamic array.
int DList::getSize() const
{
    
}

// DList.getCapacity() - Get the capacity of the dynamic array.
int DList::getCapacity() const
{
    
}

// Overloaded << operator.
std::ostream &operator<<( std::ostream &out, const DList &aList )
{
    
}
