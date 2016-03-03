#include "driver_functions.hpp"

// displayMenuOptions() - Display the program menu.
void displayMenuOptions( DList &dList )
{
    std::cout << "\n-------------------------"
        << "\n\nThe following choices are available:\n" 
        << "\nA. Add a number of random integers to end of list"
        << "\nC. Change the capacity of the list using the setCapacity function"
        << "\nE. Print the result from the empty() function"
        << "\nP. Print a copy of the entire list"
        << "\nI. Insert a new number with the insert(...) function"
        << "\nR. Remove a number with the erase() function"
        << "\nQ. Quit this test program";
}

// processMenuSelection() - Determine how the program should
// behave depending on what the user wants to do.
void processMenuSelection( char &choice, DList &dList )
{
    // If the user chooses option Q, the program terminates.
    // This is for neatness.
    if ( choice != 'Q' )
    {
        std::cout << std::endl;
    }
    
    switch ( choice )
    {
        // Option A - Insert a list of items into the array.
        case 'A':
            break;
            
        // Option C - Set a new array capacity to the list.
        case 'C':
            {
                int newCap;
                
                // Prompt the user to enter a value.
                std::cout << "Enter a new capacity for the array: ";
                std::cin  >> newCap;
                
                // Set the user's input as the new array capacity.
                dList.setCapacity( newCap );
            }
            break;
            
        // Option E - Determine if the array is empty or not.
        case 'E':
            std::cout << dList.empty() << std::endl;
            break;
            
        // Option P - Print the dynamic array.
        case 'P':
            dList.display( std::cout );
            break;
            
        // Option I - Insert a new item into the array.
        case 'I':
            break;
            
        // Option R - Remove an item from the array.
        case 'R':
            break;
    }
}
