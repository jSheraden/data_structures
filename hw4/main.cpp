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
    DList dList;              // Declare an object of class DList.
    char userChoice = '\0';   // Stores menu selections entered by the user.
    
    // Driver program loop.
    while ( userChoice != 'Q' )
    {
        // Display the program menu.
        displayMenuOptions();
        
        // Get menu selection from the user.
        std::cout << "\n\nEnter your choice: ";
        std::cin  >> userChoice;
        
        // Convert user input to uppercase.
        userChoice = toupper( userChoice );
        
        // Decide what to do based on the user's input.
        processMenuSelection( userChoice, dList );
    }
    
    std::cout << std::endl;
    
    /*
    DList dList;
    
    dList.insert( "Hello", 0 );
    dList.insert( "there,", 1 );
    dList.insert( "my", 2 );
    dList.insert( "name", 3 );
    dList.insert( "is", 4 );
    dList.insert( "Joey.", 5 );
    
    DList otherList = dList;
    
    otherList.display( std::cout );
    
    std::cout << std::endl;
    std::cout << dList.getSize() << std::endl;
    */
    
    return 0;   // Exit the program.
}
