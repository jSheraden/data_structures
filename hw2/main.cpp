// Name: Joseph Sheraden
// Project Number: 2
// Project Description: Quadratic Expressions
// Course: Data Structures
// Instructor: Bob Comer
// Date: February 21, 2016
#include <iostream>
#include <string>
#include <cmath>
#include "Quadratic.cpp"

// Driver program function prototypes.
void displayMenuOptions();
void processMenuSelection( std::string &choice, Quadratic &q1, Quadratic &q2 );

// The main function.
int main()
{
    Quadratic q1;
    Quadratic q2;
    std::string choice = "";

    std::cout << "\nTwo quadratics have been created and initialized to default values." << std::endl;

    // If the user chose option X, quit the program.
    while ( choice != "X" && choice != "x" )
    {
        // Display the menu.
        displayMenuOptions();

        // Get menu selection from user.
        std::cout << "\nEnter your choice: ";
        std::getline( std::cin, choice );

        // What does the user want to do?
        processMenuSelection( choice, q1, q2 );
    }

    std::cout << std::endl;
    
    // Exit the program.
	return 0;
}

// displayMenuOptions() - Display the program menu.
void displayMenuOptions()
{
    std::cout << "\nPlease choose one of the following:\n\n"
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

// processMenuSelection() - Display content depending on what the user
// decides to do.
void processMenuSelection( std::string &choice, Quadratic &q1, Quadratic &q2 )
{
    // Option 1.
    if ( choice == "1" )
    {
        // Display the first quadratic.
        std::cout << "\nThe first quadratic is ";
        
        q1.display();
        
        std::cout << std::endl;
    }
    
    // Option 2.
    else if ( choice == "2" )
    {
        // Display the second quadratic.
        std::cout << "\nThe second quadratic is ";
        
        q2.display();
        
        std::cout << std::endl;
    }
    
    // Option 3.
    else if ( choice == "3" )
    {
        // New values for the coefficients
        // of the first quadratic.
        std::string a, b, c;
        
        // Prompt the user to enter string values for a, b, and c.
        // This is to avoid infinite loops if and when the user
        // enters an invalid input.
        
        // Get new value for coefficient a.
        std::cout << "\nEnter a value for coefficient a: ";
        std::getline( std::cin, a );
        double newA = std::stod(a);
        
        // Get new value for coefficient b.
        std::cout << "Enter a value for coefficient b: ";
        std::getline( std::cin, b );
        double newB = std::stod(b);
        
        // Get new value for coefficient c.
        std::cout << "Enter a value for coefficient c: ";
        std::getline( std::cin, c );
        double newC = std::stod(c);
        
        // Set new coefficient values to q1.
        q1.set( newA, newB, newC );
    }
    
    // Option 4.
    else if ( choice == "4" )
    {
        // New values for the coefficients
        // of the first quadratic.
        std::string a, b, c;
        
        // Prompt the user to enter string values for a, b, and c.
        // This is to avoid infinite loops if and when the user
        // enters an invalid input.
        
        // Get new value for coefficient a.
        std::cout << "\nEnter a value for coefficient a: ";
        std::getline( std::cin, a );
        double newA = std::stod(a);
        
        // Get new value for coefficient b.
        std::cout << "Enter a value for coefficient b: ";
        std::getline( std::cin, b );
        double newB = std::stod(b);
        
        // Get new value for coefficient c.
        std::cout << "Enter a value for coefficient c: ";
        std::getline( std::cin, c );
        double newC = std::stod(c);
        
        // Set new coefficient values to q2.
        q2.set( newA, newB, newC );
    }
    
    // Option 5.
    else if ( choice == "5" )
    {
        // Display the coefficients of the first quadratic.
        std::cout << "\nThe coefficients of the first quadratic are:\n"
            << "\na = " << q1.getA()
            << "\nb = " << q1.getB()
            << "\nc = " << q1.getC()
            << std::endl;
    }
    
    // Option 6.
    else if ( choice == "6" )
    {
        
    }
    
    // Option 7.
    else if ( choice == "7" )
    {
        
    }
    
    // Option 8.
    else if ( choice == "8" )
    {
        
    }
    
    // Option 9.
    else if ( choice == "9" )
    {
        int userNum = 0;
        
        // Prompt the user to enter a number.
        std::cout << "\nEnter a number: ";
        std::cin  >> userNum;
        
        // Display the evaluated quadratic expression
        // based on the value the user entered.
        std::cout << "\nThe evaluated expression is " << q1.evaluate( userNum ) << std::endl;
        
        std::cin.ignore();
    }
    
    // Handle invalid input.
    else
    {
        std::cout << "\nNot a valid option" << std::endl;
    }
}