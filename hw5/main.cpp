// Name: Joseph Sheraden
// Project Number: 5
// Project Description: Evaluating Postfix Expressions
// Course: Data Structures
// Instructor: Bob Comer
// Date: April 29, 2016
#include <iostream>
#include <new>
#include "Stack.hpp"

// Done with a lot of help from mycodeschool on GitHub:
// https://gist.github.com/mycodeschool/7702441

// Driver function prototypes.
int evaluatePostfix( std::string exp );
int operate( int left, int right, char symbol );

// The main function.
int main()
{
    std::string expression;
    int evaluation = 0;
    char choice = '\0';
    bool quit = false;

    // Main program loop. Prompt the user to enter
    // postfix expressions until the user decides
    // to quit.
    while ( !quit )
    {
        // Get an expression from the user.
        std::cout << "Enter a postfix expression: ";
        std::getline( std::cin, expression );

        // Evaluate the expression.
        evaluation = evaluatePostfix( expression );

        // Print the evaluated expression.
        std::cout << "The evaluated expression is: " << evaluation << std::endl;

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

// evaluatePostfix() - accepts a string as an integer and
// returns the postfix evaluation of that string.
int evaluatePostfix( std::string exp )
{
    // Initialize a Stack object.
    Stack stack;

    // Loop through every value in the string.
    for ( int i = 0; i < exp.length(); i++ )
    {
        // Spaces and commas can't be used for
        // evaluating the expression.
        if ( exp[i] != ' ' || exp[i] != ',' )
        {
            // If the current char is an operator, evaluate
            // the expression.
            if ( exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' )
            {
                // Initialize two operands.
                int leftSide, rightSide;

                // Get the first operand.
                rightSide = stack.top();
                stack.pop();

                // Get the second operand.
                leftSide = stack.top();
                stack.pop();

                // Add the result of the two operands
                // to the stack.
                stack.push( operate( leftSide, rightSide, exp[i] ) );
            }

            // If the current char is an integer, add it
            // to the stack.
            else if ( exp[i] >= '0' && exp[i] <= '9' )
            {
                int operand = 0;

                while ( i < exp.length() && ( exp[i] >= '0' && exp[i] <= '9' ) )
                {
                    operand = ( operand * 10 ) + ( exp[i] - '0' );
                    i++;
                }

                i--;

                stack.push( operand );
            }
        }
    }

    return stack.top();
}

// operate() - accepts three arguments, two integers and a char.
// The char is used to determine which operation should be
// performed on the integers.
int operate( int left, int right, char symbol )
{
    if ( symbol == '+' ) { return left + right; }
    else if ( symbol == '-' ) { return left - right; }
    else if ( symbol == '*' ) { return left * right; }
    else if ( symbol == '/' ) { return left / right; }
    else
    {
        std::cerr << "*** The expression cannot be evaluated ***\n";
        return -1;
    }
}
