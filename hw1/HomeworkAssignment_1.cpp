#include "FloatUnion.hpp"
#include "HomeworkAssignment_1.hpp"

// Default constructor.
HomeworkAssignment_1::HomeworkAssignment_1()
{
    quit = false;
    numBits = 0;
    mask = 0;
	choice = "";
}

// printChar() - Display the binary representation
// of a given ASCII character.
void HomeworkAssignment_1::printChar( char ch )
{
    numBits = 8;
    mask = pow( 2, numBits - 1 );

    std::cout << "\nThe binary representation of '" << ch << "' is: ";

    for ( int i = numBits; i > 0; i-- )
    {
        if ( i != numBits && i % 4 == 0 )
            std::cout << " ";

        std::cout << ( ( ch & mask ) != 0 ? 1 : 0 );

        mask >>= 1;
    }

    std::cout << std::endl;
}

// printShort() - Display the binary representation
// of a given short integer.
void HomeworkAssignment_1::printShort( short sh )
{
    numBits = 16;
    mask = pow( 2, numBits - 1 );

    std::cout << "\nThe binary representation of " << sh << " is: ";

    for ( int i = numBits; i > 0; i-- )
    {
        if ( i != numBits && i % 4 == 0 )
            std::cout << " ";

        std::cout << ( ( sh & mask ) != 0 ? 1 : 0 );

        mask >>= 1;
    }

    std::cout << std::endl;
}

// printFloat() - Display the binary representation
// of a given real value.
void HomeworkAssignment_1::printFloat( FloatUnion fl )
{
    /* numBits = 32;
    mask = pow( 2, numBits - 1 );

    std::cout << "\nThe binary representaion of " << fl.floatValue << " is: ";

    for ( int i = numBits; i > 0; i-- )
    {
        if ( i != numBits && i % 4 == 0 )
            std::cout << " ";

        std::cout << ( ( fl.intValue & mask ) != 0 ? 1 : 0 );

        mask >>= 1;
    }

    std::cout << std::endl; */
}

// displayMenu() - Display the application menu.
void HomeworkAssignment_1::displayMenu()
{
	std::cout << "\nChoose the data type of the value you wish to enter:\n"
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
            FloatUnion userFloat;

    		std::cout << "\nEnter a float value: ";
            std::cin  >> userFloat.floatValue;

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

// choiceIsValid() - Determine if the menu selection
// entered by the user is valid.
bool HomeworkAssignment_1::choiceIsValid()
{
	return ( choice == "1" || choice == "2" || choice == "3" || choice == "Q" );
}

// run() - Start the application.
void HomeworkAssignment_1::run()
{
    std::cout << "\nThis program prints the binary representation of a given value.";
	while ( !quit )
	{
		displayMenu();
		getUserInput();
	}
}
