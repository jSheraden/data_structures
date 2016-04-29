#include <iostream>

int main()
{
    std::string expression;
    char choice;
    bool quit = false;

    // Main program loop. Prompt the user to enter
    // postfix expressions until the user decides
    // to quit.
    while ( !quit )
    {
        std::cout << "Enter an expression: ";
        std::getline( std::cin, expression );

        std::cout << "\nDo you want to enter another expression? (y/n) ";
        std::cin  >> choice;
        std::cin.ignore();

        quit = ( choice == 'y' || choice == 'y' );

        // If the user wants to evaluate another expression,
        // print another line for neatness.
        if ( !quit ) { std::cout << std::endl; }
    }

    return 0;
}
