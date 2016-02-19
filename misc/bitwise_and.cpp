#include <iostream>

int main()
{
	int num1 = 1;
	int num2 = 2;

	if ( num1 & num2 > 0 )
		std::cout << "Both numbers are greater than 0." << std::endl;
	else
		std::cout << "One or more numbers are not greater than 0." << std::endl;

	return 0;
}
