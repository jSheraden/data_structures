// Name: Joseph Sheraden
// Project Number: 7
// Project Description: Binary Search Tree
// Course: Data Structures
// Instructor: Bob Comer
// Date: May 3, 2016
#include <iostream>
#include <iomanip>
#include <new>
#include "BST.cpp"  // Included .cpp file instead of .hpp, turns out
                    // C++ doesn't allow template classes to be
                    // imported from multiple files.

// Function prototypes.
void displayMenuOptions();
void processMenuSelection( char &choice, BST<int> &bst );

// The main function.
int main()
{
    BST<int> bst;           // Binary search tree with integer nodes.
    char userChoice = '\0'; // Holds user input.

    // Main program loop.
    while ( userChoice != 'Q' )
    {
        // Print the program menu.
        displayMenuOptions();

        // Get menu selection from the user.
        std::cout << "\n\nEnter your choice: ";
        std::cin  >> userChoice;

        // Capitalize userChoice to avoid errors.
        userChoice = toupper( userChoice );

        // Get output based on what the user
        // decided to do.
        processMenuSelection( userChoice, bst );
    }

    std::cout << std::endl;

    return 0;
}

// displayMenuOptions() - Display the program menu.
void displayMenuOptions()
{
    std::cout << "\n-------------------------"
        << "\nSelect an option from the menu below:\n"
        << "\nD. Display the binary search tree."
        << "\nI. Insert a value into the tree."
        << "\nH. Get the height of the binary search tree."
        << "\nL. Get the leaf count of the binary search tree."
        << "\nS. Search for a specific value in the tree."
        << "\nQ. Quit";
}

// processMenuSelection() - Determine how the program should
// behave depending on what the user wants to do.
void processMenuSelection( char &choice, BST<int> &bst )
{
    // Evaluate the menu option entered by
    // the user.
    switch ( choice )
    {
        case 'D':
            bst.graph( std::cout );
            break;
        case 'I':
            {
                int val;

                // Get a value from the user to be
                // inserted into the tree.
                std::cout << "\nEnter an integer: ";
                std::cin  >> val;

                bst.insert( val );

                std::cout << "\nThe value " << val << " has been inserted into the tree." << std::endl;
            }
            break;
        case 'H':
            std::cout << "\nThe height of the binary search tree is " << bst.height() << " nodes." << std::endl;
            break;
        case 'L':
            std::cout << "\nThe total number of nodes in the tree is " << bst.leafCount() << "." << std::endl;
            break;
        case 'S':
            {
                int searchItem;

                // Get a value from the user to be
                // searched for in the tree.
                std::cout << "\nEnter an integer: ";
                std::cin  >> searchItem;

                std::cout << ( bst.search( searchItem ) ? "\nThat value is in the list" : "\nThat value is not in the list" ) << std::endl;
            }
            break;
        case 'Q':
            std::cout << std::endl;
            break;
    }
}
