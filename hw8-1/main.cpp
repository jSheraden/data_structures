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

    std::cout << std::endl;
    std::cout << "Success!" << std::endl;

    return 0;
}

// displayMenuOptions() - Prints a list of options
// for the user to choose from.
void displayMenuOptions()
{
    std::cout << "\n-------------------------"
        << "\nSelect an option from the menu below.\n"
        << "\nI. Insert a new record or update an existing record"
        << "\nF. Find a record"
        << "\nS. Get the number of records"
        << "\nQ. Quit";
}

// processMenuSelection() - Determines what the program
// should do based on the menu option that the user
// has entered.
void processMenuSelection( char &choice, Table &table )
{

}
