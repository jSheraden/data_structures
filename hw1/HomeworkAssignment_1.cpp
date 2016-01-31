#include "HomeworkAssignment_1.h"

// Default constructor.
HomeworkAssignment_1::HomeworkAssignment_1()
{
	choice = "";
	quit = false;
}

// printChar()
void HomeworkAssignment_1::printChar( char ch )
{
    unsigned short numBits = 8;
    char mask = pow( 2, numBits - 1 );

    std::cout << std::endl;

    for ( int i = numBits; i > 0; i-- )
    {
        if ( i != numBits && i % 4 == 0 )
            std::cout << " ";

        std::cout << ( ( ch & mask ) != 0 ? 1 : 0 );

        mask >>= 1;
    }

    std::cout << std::endl;
}

// printShort()
void HomeworkAssignment_1::printShort( short sh )
{
    unsigned short numBits = 16;
    unsigned short mask = pow( 2, numBits - 1 );

    std::cout << std::endl;

    for ( int i = numBits; i > 0; i-- )
    {
        if ( i != numBits && i % 4 == 0 )
            std::cout << " ";

        std::cout << ( ( sh & mask ) != 0 ? 1 : 0 );

        mask >>= 1;
    }

    std::cout << std::endl;
}

// printFloat()
void HomeworkAssignment_1::printFloat( float fl )
{
    /* unsigned short numBits = 32;
    float mask = pow( 2, numBits - 1 );

    std::cout << std::endl;

    for ( int i = numBits; i > 0; i-- )
    {
        if ( i != numBits && i % 4 == 0 )
            std::cout << " ";

        std::cout << ( ( fl & mask ) != 0 ? 1 : 0 );

        mask >>= 1;
    }

    std::cout << std::endl; */
}

// displayMenu() - Display the application menu.
void HomeworkAssignment_1::displayMenu()
{
	std::cout << "\nPlease choose an option:\n"
		<< "\n1. Char"
		<< "\n2. Short"
		<< "\n3. Float"
		<< "\nQ. Quit"
		<< "\n\nEnter your selection: ";
}

// getUserInput() - Prompt the user to enter
// a select an option from the menu.
void HomeworkAssignment_1::getUserInput()
{
	std::getline( std::cin, choice );
	while ( !choiceIsValid() )
	{
		std::cout << "\nEnter a valid option: ";
		std::getline( std::cin, choice );
	}

    if ( choice != "Q" )
    {
    	if ( choice == "1" )
        {
            char userChar;

            std::cout << "\nEnter a char: ";
            std::cin  >> userChar;

    		printChar( userChar );
        }
    	else if ( choice == "2" )
        {
            short userShort;

    		std::cout << "\nEnter a short integer: ";
            std::cin  >> userShort;

            printShort( userShort );
        }
    	else if ( choice == "3" )
        {
            float userFloat;

    		std::cout << "\nEnter a float value: ";
            std::cin  >> userFloat;

            printFloat( userFloat );
        }

        std::cin.ignore();
    }
	else
	{
		std::cout << "\nGoodbye...\n" << std::endl;
		quit = true;
	}
}

// choiceIsValid() - Determine if the value entered
// by the user is valid.
bool HomeworkAssignment_1::choiceIsValid()
{
	if ( choice == "1" || choice == "2" || choice == "3" || choice == "Q" )
		return true;
	else
        return false;
}

// run() - Run the application.
void HomeworkAssignment_1::run()
{
	while ( !quit )
	{
		displayMenu();
		getUserInputs();
	}
}
