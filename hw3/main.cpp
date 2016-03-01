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
    DList dList( 5 );
    char userChoice = '\0';
    
    while ( toupper( userChoice ) != 'X' )
    {
        displayMenuOptions( dList );
        
        std::cout << "Enter your choice: ";
        std::cin  >> userChoice;
        
        processMenuSelection( userChoice );
    }
    
    std::cout << std::endl;
    
    return 0;
}
