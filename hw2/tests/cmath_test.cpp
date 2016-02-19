#include <iostream>
#include <cmath>

int main()
{
    int num;

    std::cout << "Enter an integer: ";
    std::cin  >> num;

    std::cout << "The value of that number squared is: " << pow( num, 2 ) << std::endl;

    return 0;
}

