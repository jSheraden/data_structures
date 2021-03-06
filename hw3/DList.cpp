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
        std::cerr << "\n*** Inadequate memory to allocate storage for list ***\n";
        exit( 1 );
    }
}

// DList class destructor.
DList::~DList()
{
    delete[] myArray;
}

// Overloaded = operator for DList.
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
                std::cerr << "\n*** Inadequate memory to allocate stack ***\n";
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

// DList.empty() - Check if the dynamic array is empty.
bool DList::empty() const
{
    return mySize == 0;
}

// DList.insert() - Insert an element into the dynamic array.
void DList::insert( ElementType item, int pos )
{
    // If the array has reach max capacity, terminate the program.
    if ( mySize == 1024 )
    {
        std::cerr << "\n*** No space for this list element -- terminating execution ***\n";
        exit( 1 );
    }
    
    // If item position is out of bounds, return an error message.
    if ( pos < 0 || pos > mySize )
    {
        std::cerr << "\n*** Illegal location to insert -- " << pos << ". List unchanged ***\n";
        return;
    }
    
    // First shift array elements right to make room for item.
    for ( int i = mySize; i > pos; i-- )
    {
        myArray[i] = myArray[i - 1];
    }
    
    // Now insert item at position pos and increase list size.
    myArray[pos] = item;
    mySize++;
    
    std::cout << "\nA new item with value " << item
        << " has been added at position " << pos
        << "." << std::endl;
}

// DList.erase() - Remove an element from the dynamic array.
void DList::erase( int pos )
{
    // If the list is empty, display an error message and return.
    if ( mySize == 0 )
    {
        std::cerr << "\n*** List is empty ***\n";
        return;
    }
    
    // If pos is out of bounds, display an error message and return.
    if ( pos < 0 || pos >= mySize )
    {
        std::cerr << "\n*** Illegal location to delete -- " << pos << ". List unchanged ***\n";
        return;
    }
    
    // Shift array elements left to close the gap.
    for ( int i = pos; i < mySize; i++ )
    {
        myArray[i] = myArray[i + 1];
    }
    
    // Decrease list size.
    mySize--;
    
    std::cout << "\nThe item at position " << pos << " has been deleted." << std::endl;
}

// DList.display() - Display the dynamic array.
void DList::display( std::ostream &out ) const
{
    for ( int i = 0; i < mySize; i++ )
    {
        out << myArray[i] << " ";
    }
}

// DList.setCapacity() - Set a new upper limit to the number of
// list items the dynamic array can hold.
void DList::setCapacity( int newCapacity )
{
    if ( newCapacity > myCapacity )
    {
        myCapacity = newCapacity;
        std::cout << "\nA new capacity has been set to the dynamic array." << std::endl;
    }
    else
    {
        std::cerr << "\n*** New capacity must be higher than previous capacity ***\n";
    }
}

// DList.getSize() - Get the current size of the dynamic array.
int DList::getSize() const
{
    return mySize;
}

// DList.getCapacity() - Get the capacity of the dynamic array.
int DList::getCapacity() const
{
    return myCapacity;
}

// Overloaded << operator.
std::ostream &operator<<( std::ostream &out, const DList &aList )
{
    aList.display( out );
    return out;
}
