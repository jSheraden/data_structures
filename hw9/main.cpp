#include <iostream>
#include <cmath>

// Function prototypes.
bool getUserChoice();
void heapify( int *arr, int size );
void heapSort( int *arr, int size );
void percolateDown( int *arr, int start, int end );

// The main function.
int main()
{
    int *myArr;
    int size;
    bool quit = false;

    // Prompt the user for input until
    // the user decides to quit.
    while ( !quit )
    {
        // Get the number of items the array will hold
        // from the user.
        std::cout << "Enter the size of the array: ";
        std::cin  >> size;

        // Allocate memory for the array.
        myArr = new( std::nothrow ) int[size];

        // Get user input for each item in the array.
        for ( int i = 0; i < size; i++ )
        {
            std::cout << "\nEnter integer #" << ( i + 1 ) << ": ";
            std::cin  >> myArr[i];
        }

        // Call functions to heapify and sort the array.
        heapify( myArr, size );
        heapSort( myArr, size );

        std::cout << std::endl;

        // Display the array.
        for ( int i = 0; i < size; i++ )
            std::cout << myArr[i] << " ";

        std::cout << std::endl;

        // Does the user want to quit?
        quit = getUserChoice();

        // Deallocate the memory held by the
        // dynamic array.
        delete myArr;
    }

    return 0;   // Exit the program.
}

// getUserChoice() - basic menu prompting the
// user to decide whether or not to quit the
// program.
bool getUserChoice()
{
    char choice;

    std::cout << "\nDo you want to enter another array? (Y/N) ";
    std::cin  >> choice;

    // Capitalize the user's selection.
    choice = toupper( choice );

    // Make sure the user's menu selection is valid.
    while ( choice != 'Y' && choice != 'N' )
    {
        std::cout << "\nEnter a valid option: ";
        std::cin  >> choice;
        choice = toupper( choice );
    }

    // If the user wants to quit, exit the loop.
    if ( choice == 'N' )
        return true;
    else
        std::cout << std::endl;   // Print a line for neatness before exiting.
}

// heapify() - accepts an array of integers as
// an argument and turns it into a heap.
void heapify( int *arr, int size )
{
    int start = floor( ( size - 2 ) / 2 );

    while ( start >= 0 )
    {
        percolateDown( arr, start, size - 1 );
        start--;
    }
}

// heapSort() - accepts an array of integers and
// its size as arguments and sorts the array.
void heapSort( int *arr, int size )
{
    heapify( arr, size );

    int temp;
    int end = size - 1;

    while ( end > 0 )
    {
        temp = arr[0];
        arr[0] = arr[end];
        arr[end] = temp;
        end--;

        percolateDown( arr, 0, end );
    }
}

// percolateDown()
void percolateDown( int *arr, int start, int end )
{
    int root = start;

    while ( ( 2 * root ) + 1 <= end )
    {
        int child = ( 2 * root ) + 1;
        int swap = root;

        if ( arr[swap] < arr[child] )
            swap = child;

        if ( child + 1 <= end && arr[swap] < arr[child + 1] )
            swap = child + 1;

        if ( swap == root )
            return;
        else
        {
            int temp = arr[root];
            arr[root] = arr[swap];
            arr[swap] = temp;

            root = swap;
        }
    }
}
