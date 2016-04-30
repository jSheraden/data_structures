#include <iostream>
#include <new>
#include "Stack.hpp"

int main()
{
    Stack stack;
    std::string expression;
    char choice;
    bool quit = false;

    // Main program loop. Prompt the user to enter
    // postfix expressions until the user decides
    // to quit.
    while ( !quit )
    {
        // Get an expression from the user.
        std::cout << "Enter an expression: ";
        std::getline( std::cin, expression );

        // Does the user choose to quit?
        std::cout << "\nDo you want to enter another expression? (y/n) ";
        std::cin  >> choice;
        std::cin.ignore();

        // Evaluate the user's choice of whether or
        // not to quit.
        quit = ( choice == 'N' || choice == 'n' );

        // If the user wants to evaluate another expression,
        // print another line for neatness.
        if ( !quit ) { std::cout << std::endl; }
    }

    // Exit the program.
    return 0;
}
