#include <iostream>
#include "hw1/FloatUnion.hpp"

int main()
{
	FloatUnion floatUnion;

	floatUnion.floatValue = 5.2;

	std::cout << floatUnion.intValue << std::endl;

	return 0;
}
