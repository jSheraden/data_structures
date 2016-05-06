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

// Stackoverflow helped a lot with the height() and findHeight()
// member functions of the BST class.
// http://stackoverflow.com/questions/2597637/finding-height-in-binary-search-tree

// I found the site Encrypted3D to be very helpful with implementing
// the leafCount() and findLeafCount() member functions.
// https://encrypt3d.wordpress.com/2010/09/29/how-to-count-number-of-nodes-in-a-binary-search-tree/

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

    return 0;
}

// displayMenuOptions() - Display the program menu.
void displayMenuOptions()
{
    std::cout << "\n-------------------------"
        << "\nSelect an option from the menu below:\n"
        << "\nD. Display the binary search tree."
        << "\nE. Check if the tree is empty or not."
        << "\nH. Get the height of the binary search tree."
        << "\nI. Insert a value into the tree."
        << "\nN. Get the total number of nodes in the tree."
        << "\nO. Display every value in the tree in ascending order."
        << "\nR. Remove a value from the binary search tree."
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
        // Option D.
        case 'D':
            bst.graph( std::cout );
            break;

        // Option E.
        case 'E':
            std::cout << ( bst.empty() ? "\nThe tree is empty." : "\nThe tree is not empty." ) << std::endl;
            break;

        // Option H.
        case 'H':
            std::cout << "\nThe height of the binary search tree is " << bst.height() << " nodes." << std::endl;
            break;

        // Option I.
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

        // Option N.
        case 'N':
            std::cout << "\nThe total number of nodes in the tree is " << bst.leafCount() << "." << std::endl;
            break;

        // Option O.
        case 'O':
            {
                std::cout << "\nValues in the tree: ";
                bst.inOrder( std::cout );
                std::cout << std::endl;
            }
            break;

        // Option R.
        case 'R':
            {
                int removeVal;

                std::cout << "\nEnter a value to be removed from the tree: ";
                std::cin  >> removeVal;

                bst.remove( removeVal );

                std::cout << "\nThe value " << removeVal << " has been removed from the tree." << std::endl;
            }
            break;

        // Option S.
        case 'S':
            {
                int searchItem;

                // Get a value from the user to be
                // searched for in the tree.
                std::cout << "\nEnter an integer: ";
                std::cin  >> searchItem;

                std::cout << ( bst.search( searchItem ) ? "\nThat value is in the tree." : "\nThat value is not in the tree." ) << std::endl;
            }
            break;

        // If the user chooses to quit, nothing
        // needs to be done here.
        case 'Q':
            break;

        // If the user enters an invalid option,
        // prompt the user to enter a valid
        // option.
        default:
            std::cout << "\nEnter a valid option." << std::endl;
            break;
    }
}
