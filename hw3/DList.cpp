#include "DList.hpp"

// Default constructor.
DList::DList() : mySize( 0 ), myCapacity( 0 )
{
    std::cout << "Testing..." << std::endl;
}

<<<<<<< HEAD
// Overloaded constructor.
DList::DList( int maxSize ) : mySize( 0 ), myCapacity( maxSize )
{
    
}

// DList.empty() - Empty the dynamic array.
bool DList::empty()
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
void DList::display( std::ostream &out )
{
    
}

// DList.getSize() - Get the current size of the dynamic array.
int DList::getSize()
{
    
}

// DList.getCapacity() - Get the capacity of the dynamic array.
int DList::getCapacity()
{
    
}

// Overloaded << operator.
std::ostream &operator<<( std::ostream &out, const DList &aList )
{
    
=======
// DList.empty()
bool DList::empty() const
{

}

// DList.insert()
void DList::insert( ElementType item, int pos )
{

}

// DList.erase()
void DList::erase( int pos )
{

}

// DList.display()
void DList::display( std::ostream &out ) const
{

}

// DList.getSize()
int DList::getSize() const
{

}

// DList.getCapacity()
int DList::getCapacity() const
{

>>>>>>> 6370c401910c9680aad8685cdefea9b9909a564b
}
