// Name: Joseph Sheraden
// Project Number: 2
// Project Description: Quadratic Expressions
// Course: Data Structures
// Instructor: Bob Comer
// Date: February 19, 2016
#include <iostream>
#include <string>
#include <cmath>
#include "Quadratic.cpp"

// Driver program function prototypes.
void displayMenuOptions();

// The main function.
int main()
{
    Quadratic quadratic;
    std::string choice = "";

    std::cout << "\nTwo quadratics have been created and initialized to default values.\n" << std::endl;

    // If the user chose option X, quit the program.
    while ( choice != "X" && choice != "x" )
    {
        // Display the menu.
        displayMenuOptions();

        // Get menu selection from user.
        std::cout << "\nEnter your choice: ";
        std::getline( std::cin, choice );

        // What does the user want to do?
        if ( choice == "1" )
        {
            // code to display first quadratic
        }
        else if ( choice == "9" )
        {
            // code to input a float and display product
        }
        else
        {
            std::cout << "\nNot a valid option\n" << std::endl;
        }
    }

    // Exit the program.
	return 0;
}

// displayMenuOptions() - Display the driver program menu.
void displayMenuOptions()
{
    std::cout << "Please choose one of the following:\n\n"
        << "1. Display first quadratic\n"
        << "2. Display second quadratic\n"
        << "3. Modify the coefficients of first quadratic\n"
        << "4. Modify the coefficients of second quadratic\n"
        << "5. Display the coefficients of first quadratic\n"
        << "6. Evaluate the first quadratic at a given value of x\n"
        << "7. Display the number of roots, smallest root and largest root for first quadratic\n"
        << "8. Display the sum of first and second quadratic\n"
        << "9. Display the product of first quadratic and a given floating-point value\n"
        << "X. Exit"
        << std::endl;
}
