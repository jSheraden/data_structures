#include <iostream>

// Function prototypes.
int heapify( int *arr, int size );
int heapSort( int *arr, int size );

// The main function.
int main()
{
    int *myArr;
    int size;
    int userNum;
    char choice;
    bool quit = false;

    // Prompt the user for input until
    // the user decides to quit.
    while ( !quit )
    {
        // Get the number of items the array will hold
        // from the user.
        std::cout << "Enter the size of the array: ";
        std::cin  >> size;

        myArr = new( std::nothrow ) int[size];

        for ( int i = 0; i < size; i++ )
        {
            std::cout << "\nEnter integer #" << ( i + 1 ) << ": ";
            std::cin  >> myArr[i];
        }

        std::cout << std::endl;

        for ( int i = 0; i < size; i++ )
            std::cout << myArr[i] << std::endl;

        // Does the user want to quit?
        std::cout << "\nDo you want to enter another array? (Y/N) ";
        std::cin  >> choice;

        // Capitalize the user's selection.
        choice = toupper( choice );

        // Make sure the user's menu selection is valid.
        // If it is, and if the user chooses to quit,
        // exit the loop.
        if ( choice != 'Y' && choice != 'N' )
            std::cout << "\nEnter a valid option: " << std::endl;
        else if ( choice == 'N' )
            quit = true;

        // Deallocate the memory held by the
        // dynamic array.
        delete myArr;

        std::cout << std::endl;
    }

    // Exit the program.
    return 0;
}

// heapify() - accepts an array of integers as
// an argument and turns it into a heap.
int heapify( int *arr, int size )
{

}

// heapSort() - accepts an array of integers and
// its size as arguments and sorts the array.
int heapSort( int *arr, int size )
{

}
