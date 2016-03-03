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
void processMenuSelection( char &choice )
{
    switch ( choice )
    {
        case 'A':
            break;
        case 'C':
            break;
        case 'E':
            break;
        case 'P':
            break;
        case 'I':
            break;
        case 'R':
            break;
        case 'Q':
            break;
    }
}
