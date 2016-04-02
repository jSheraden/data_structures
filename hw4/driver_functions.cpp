#include "driver_functions.hpp"

// displayMenuOptions() - Display the program menu.
void displayMenuOptions()
{
    std::cout << "\n-------------------------"
        << "\n\nThe following choices are available:\n" 
        << "\nE. Print the result from the empty() function"
        << "\nF. Print the index of a specific value in the list"
        << "\nP. Print a copy of the entire list"
        << "\nI. Insert a new string with the insert(...) function"
        << "\nR. Remove a list item with the erase() function"
        << "\nQ. Quit this test program";
}

// processMenuSelection() - Determine how the program should
// behave depending on what the user wants to do.
void processMenuSelection( char &choice, DList &dList )
{
    std::cin.ignore();
    
    // If the user chooses option Q, the program terminates.
    // This is for neatness.
    if ( choice != 'Q' )
    {
        std::cout << std::endl;
    }
    
    switch ( choice )
    {
        // Option E - Determine if the list is empty or not.
        case 'E':
            std::cout << ( dList.empty() ? "The list is empty." : "The list is not empty." ) << std::endl;
            break;
        
        // Option F - Print the index of a specific value in the list.
        case 'F':
            {
                ElementType searchStr;
                int pos;
                std::cout << "Enter a string: ";
                std::getline( std::cin, searchStr );
                
                pos = dList.find( searchStr );
                
                if ( pos == -1 )
                {
                    std::cout << "\nThat string is not in the list." << std::endl;
                }
                else
                {
                    std::cout << "\nThe position of that string in the list is " << pos << "." << std::endl;
                }
            }
            break;
            
        // Option P - Print the list.
        case 'P':
            dList.display( std::cout );
            std::cout << std::endl;
            break;
            
        // Option I - Insert a new item into the list.
        case 'I':
            {
                ElementType newItem;
                int newItemPos;
                
                // Prompt the user to enter a value for a new list item.
                std::cout << "Enter a string for a new list item: ";
                std::getline( std::cin, newItem );
                
                // Now get a value for the new item's position.
                std::cout << "Where in the array should this new item be? ";
                std::cin  >> newItemPos;
                
                // Set the user's input as a new item in the list.
                dList.insert( newItem, newItemPos );
            }
            break;
            
        // Option R - Remove an item from the list.
        case 'R':
            {
                int itemPos;
                
                // Prompt the user to enter the position of the item to
                // be erased.
                std::cout << "Enter the position in the list of the item to be erased: ";
                std::cin  >> itemPos;
                
                // Remove the item from the list.
                dList.erase( itemPos );
            }
            break;
    }
}
