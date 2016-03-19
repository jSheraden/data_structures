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
            {
                std::cin.ignore();
                
                std::string newItems;
                std::string temp = "";
                int size;
                
                // Prompt the user to enter several integers on one line.
                std::cout << "Enter one or more values to be inserted into the list (separated by spaces): ";
                std::getline( std::cin, newItems );
                
                // Break the string into multiple values and insert them
                // into the array.
                size = newItems.size();
                for ( int i = 0; i < size + 1; i++ )
                {
                    if ( newItems[i] != ' ' && i < size )
                    {
                        temp += newItems[i];
                    }
                    else
                    {
                        dList.insert( std::stoi( temp ), dList.getSize() );
                        temp = "";
                    }
                }
                
            }
            break;
        
        // Option E - Determine if the array is empty or not.
        case 'E':
            std::cout << dList.empty() << std::endl;
            break;
            
        // Option P - Print the dynamic array.
        case 'P':
            dList.display( std::cout );
            std::cout << std::endl;
            break;
            
        // Option I - Insert a new item into the array.
        case 'I':
            {
                ElementType newItem;
                int newItemPos;
                
                // Prompt the user to enter a value for a new list item.
                std::cout << "Enter an integer for a new list item: ";
                std::cin  >> newItem;
                
                // Now get a value for the new item's position.
                std::cout << "Where in the array should this new item be? ";
                std::cin  >> newItemPos;
                
                // Set the user's input as a new item in the array.
                dList.insert( newItem, newItemPos );
            }
            break;
            
        // Option R - Remove an item from the array.
        case 'R':
            {
                int itemPos;
                
                // Prompt the user to enter the position of the item to
                // be erased.
                std::cout << "Enter the position in the list of the item to be erased: ";
                std::cin  >> itemPos;
                
                // Remove the item from the array.
                dList.erase( itemPos );
            }
            break;
    }
}
