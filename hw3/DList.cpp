#include "DList.hpp"

// Default constructor.
DList::DList() : mySize( 0 ), myCapacity( 0 )
{
    myArray = new( std::nothrow ) ElementType;
    assert( myArray != 0 );
}

// Overloaded constructor.
DList::DList( int maxSize ) : mySize( 0 ), myCapacity( maxSize )
{
    myArray = new( std::nothrow ) ElementType[maxSize];
    assert( myArray != 0 );
}

// Second overloaded constructor.
DList::DList( const DList &origList )
: mySize( origList.mySize ), myCapacity( origList.myCapacity )
{
    myArray = new( std::nothrow ) ElementType[myCapacity];

    // If myArray is not empty, assign the elements of
    // origList to this list.
    if ( myArray != 0 )
    {
        for ( int i = 0; i < mySize; i++ )
        {
            myArray[i] = origList.myArray[i];
        }
    }
    
    // If not, return an error message.
    else
    {
        std::cerr << "*** Inadequate memory to allocate storage for list ***\n";
        exit( 1 );
    }
}

// DList class destructor.
DList::~DList()
{
    delete[] myArray;
}

const DList &DList::operator=( const DList &rightHandSide )
{
    if ( this != &rightHandSide )
    {
        // Allocate a new array if necessary.
        if ( myCapacity != rightHandSide.myCapacity )
        {
            delete[] myArray;
            myCapacity = rightHandSide.myCapacity;
            myArray = new( std::nothrow ) ElementType[myCapacity];
            
            if ( myArray == 0 )
            {
                std::cerr << "*** Inadequate memory to allocate stack ***\n";
                exit( 1 );
            }
        }
        
        // Copy rightHandSide's list elements into this new array.
        mySize = rightHandSide.mySize;
        for ( int i = 0; i < mySize; i++ )
        {
            myArray[i] = rightHandSide.myArray[i];
        }
    }
    
    return *this;
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
    aList.display( out );
    return out;
}
