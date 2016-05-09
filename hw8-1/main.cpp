// Name: Joseph Sheraden
// Project Number: 8-1
// Project Description: Hash Table with Linear Probing
// Course: Data Structures
// Instructor: Bob Comer
// Date: May 8, 2016
#include <iostream>
#include <cassert>
#include <iomanip>
#include "Table.hpp"

// Function prototypes.
void displayMenuOptions();
void processMenuSelection( char &choice, Table &table );

// The main function.
int main()
{
    Table table;            // Initialize a hash table.
    char userChoice = '\0'; // Holds menu option input from the user.

    while ( userChoice != 'Q' )
    {
        // Display the program menu.
        displayMenuOptions();

        // Prompt the user to enter a menu option.
        std::cout << "\n\nEnter an option: ";
        std::cin  >> userChoice;

        // Capitalize all menu options entered by
        // the user.
        userChoice = toupper( userChoice );

        // Decide what to do based on the user's input.
        processMenuSelection( userChoice, table );
    }

    return 0;
}

// displayMenuOptions() - Prints a list of options
// for the user to choose from.
void displayMenuOptions()
{
    std::cout << "\n-------------------------"
        << "\nSelect an option from the menu below:\n"
        << "\nD. Display the hash table."
        << "\nI. Insert a new record or update an existing record."
        << "\nF. Find a record."
        << "\nR. Delete a record from the hash table."
        << "\nS. Get the number of records."
        << "\nQ. Quit.";
}

// processMenuSelection() - Determines what the program
// should do based on the menu option that the user
// has entered.
void processMenuSelection( char &choice, Table &table )
{
    switch( choice )
    {
        // Option D.
        case 'D':
            table.display();
            break;

        // Option I.
        case 'I':
            {
                RecordType rec; // New record to be entered into the table.

                // Get the new record's key from the user.
                std::cout << "\nEnter key (int >= 0) for record: ";
                std::cin  >> rec.key;

                // Get the new record's data from the user.
                std::cout << "Enter data (int) for record: ";
                std::cin  >> rec.data;

                // Insert that value into the table.
                table.insert( rec );

                std::cout << "\nThe record has been entered into the table." << std::endl;
            }
            break;

        // Option F.
        case 'F':
            {
                RecordType rec; // Record to search the table with.
                int key;        // Holds the key to search for.
                bool found;     // Has the key been found in the table?

                // Prompt the user to enter a key to search for.
                std::cout << "\nEnter key (int >= 0) to search for: ";
                std::cin  >> key;

                // Search for the key in the table.
                table.find( key, found, rec );

                if ( found )
                {
                    std::cout << "\nRecord was found." << std::endl;
                    std::cout << "    Key         = " << std::setw( 8 ) << rec.key << std::endl;
                    std::cout << "    Data        = " << std::setw( 8 ) << rec.data << std::endl;
                }
                else
                    std::cout << "\nRecord with key " << key << " not found." << std::endl;
            }
            break;

        // Option R.
        case 'R':
            {
                int key; // Holds the index of the record to be removed.

                // Get a key from the user.
                std::cout << "\nEnter the key of the record to be removed: ";
                std::cin  >> key;

                // Remove the record at the given key.
                table.remove( key );
            }
            break;

        // Option S.
        case 'S':
            std::cout << "\nThere are " << table.size() << " record(s) in the table." << std::endl;
            break;

        // Option Q.
        case 'Q':
            std::cout << "\nGoodbye..." << std::endl;
            break;
    }
}
