// Name: Joseph Sheraden
// Project Number: 3
// Project Description: List Class with a Dynamic Array
// Course: Data Structures
// Instructor: Bob Comer
// Date: February 23, 2016
#include <iostream>
#include <cassert>
#include "DList.cpp"
#include "driver_functions.cpp"

int main()
{
    DList dList( 5 );         // Declare an object of class DList.
    char userChoice = '\0';   // Stores menu selections entered by the user.
    
    // Driver program loop.
    while ( toupper( userChoice ) != 'Q' )
    {
        // Display the program menu.
        displayMenuOptions( dList );
        
        // Get menu selection from the user.
        std::cout << "Enter your choice: ";
        std::cin  >> userChoice;
        
        // Decide what to do based on the user's input.
        processMenuSelection( userChoice );
    }
    
    std::cout << std::endl;
    
    return 0;   // Exit the program.
}
