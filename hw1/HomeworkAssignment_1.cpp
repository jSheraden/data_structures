#include "FloatUnion.hpp"
#include "HomeworkAssignment_1.hpp"

// Default constructor.
HomeworkAssignment_1::HomeworkAssignment_1()
{
    quit = false;   // Setting quit to false allows the program loop to start.
	choice = "";    // The user's menu selection starts out as an empty string.
}

// printChar() - Display the binary representation
// of a given ASCII character.
void HomeworkAssignment_1::printChar( char ch )
{
    // Number of bits used to store a char.
    unsigned short numBits = 8;

    // Initialize the mask variable as 2 ^ 7.
    unsigned int mask = pow( 2, numBits - 1 );

    std::cout << "\nThe binary representation of '" << ch << "' is: ";

    // Determine if each individual bit is 1 or 0.
    for ( int i = numBits; i > 0; i-- )
    {
        // Print a space every four bits.
        if ( i != numBits && i % 4 == 0 )
        {
            std::cout << " ";
        }

        // If neither the parameter nor mask are equal to 0, print 1.
        // Otherwise, print 0.
        std::cout << ( ( ch & mask ) != 0 ? 1 : 0 );

        mask >>= 1;   // Shift the bits in mask one space to the right.
    }

    std::cout << std::endl;
}

// printShort() - Display the binary representation
// of a given short integer.
void HomeworkAssignment_1::printShort( short sh )
{
    // Number of bits used to store a short integer.
    unsigned short numBits = 16;

    // Initialize the mask variable as 2 ^ 15.
    unsigned int mask = pow( 2, numBits - 1 );

    std::cout << "\nThe binary representation of " << sh << " is: ";

    // Determine if each individual bit is 1 or 0.
    for ( int i = numBits; i > 0; i-- )
    {
        // Print a space every four bits.
        if ( i != numBits && i % 4 == 0 )
        {
            std::cout << " ";
        }

        // If neither the parameter or mask are equal to 0, print 1.
        // Otherwise print 0.
        std::cout << ( ( sh & mask ) != 0 ? 1 : 0 );

        mask >>= 1;   // Shift the bits in mask one space to the right.
    }

    // Print a new line for neatness.
    std::cout << std::endl;
}

// printFloat() - Display the binary representation
// of a given floating-point value.
void HomeworkAssignment_1::printFloat( float fl )
{
    // Floats must be represented as integers in order for the
    // algorithm to return the correct value. To do this, we use
    // a union.
    FloatUnion floatUnion;
    floatUnion.floatValue = fl;

    // Number of bits used to store a floating-point number.
    unsigned short numBits = 32;

    // Initialize the mask variable to 2 ^ 31.
    unsigned int mask = pow( 2, numBits - 1 );

    std::cout << "\nThe binary representation of " << floatUnion.floatValue << " is: ";

    // Determine if each individual bit is 1 or 0.
    for ( int i = numBits; i > 0; i-- )
    {
        // Print a space every four bits.
        if ( i != numBits && i % 4 == 0 )
        {
            std::cout << " ";
        }

        // If neither floatUnion.intValue nor mask are equal to 0, print 1.
        // Otherwise, print 0.
        std::cout << ( ( floatUnion.intValue & mask ) != 0 ? 1 : 0 );

        mask >>= 1;   // Shift the bits in mask one space to the right.
    }

    // Print a new line for neatness.
    std::cout << std::endl;
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
    // Get input from the user.
	std::getline( std::cin, choice );

    // If the user enters something other than
    // a menu option, prompt the user to make
    // a valid selection.
	while ( !choiceIsValid() )
	{
		std::cout << "\nEnter a valid option: ";
		std::getline( std::cin, choice );
	}

    // If the user doesn't choose to exit the program.
    if ( choice != "Q" )
    {
        // If the user chose to enter a char.
    	if ( choice == "1" )
        {
            char userChar;

            std::cout << "\nEnter a char: ";
            std::cin  >> userChar;

    		printChar( userChar );
        }

        // If the user chose to enter a short integer.
    	else if ( choice == "2" )
        {
            short userShort;

    		std::cout << "\nEnter a short integer: ";
            std::cin  >> userShort;

            printShort( userShort );
        }

        // If the user chose to enter a floating-point value.
    	else if ( choice == "3" )
        {
            float userFloat;

    		std::cout << "\nEnter a float value: ";
            std::cin  >> userFloat;

            printFloat( userFloat );
        }

        std::cin.ignore();
    }

    // If the user chose to quit, end the loop.
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
		displayMenu();    // Display the list of options for the user.
		getUserInput();   // What does the user want to do?
	}
}
