// Name: Joseph Sheraden
// Project Number: 4
// Project Description: Linked-list Processing
// Course: Data Structures
// Instructor: Bob Comer
// Date: March 18, 2016
#include <iostream>
#include <cassert>
#include "DList.cpp"
#include "driver_functions.cpp"

int main()
{
    /*
    DList dList( 5 );         // Declare an object of class DList.
    char userChoice = '\0';   // Stores menu selections entered by the user.
    
    // Driver program loop.
    while ( userChoice != 'Q' )
    {
        // Display the program menu.
        displayMenuOptions( dList );
        
        // Get menu selection from the user.
        std::cout << "\n\nEnter your choice: ";
        std::cin  >> userChoice;
        
        // Convert user input to uppercase.
        userChoice = toupper( userChoice );
        
        // Decide what to do based on the user's input.
        processMenuSelection( userChoice, dList );
    }
    
    std::cout << std::endl;
    */
    
    DList dList;
    
    dList.insert( 5, 0 );
    dList.insert( 10, 1 );
    dList.insert( 3, 2 );
    dList.insert( 4, 3 );
    dList.insert( 7, 4 );
    dList.erase( 2 );
    dList.insert( 5, 5 );
    dList.display( std::cout );
    
    std::cout << std::endl;
    std::cout << dList.getSize() << std::endl;
    std::cout << "Success!" << std::endl;
    
    return 0;   // Exit the program.
}
