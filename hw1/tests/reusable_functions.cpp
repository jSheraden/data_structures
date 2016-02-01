// reusablefunctions.cpp
//
// This program tests the reusability of the static member functions
// in the HomeworkAssignment_1 class. As you can see, the functions
// can be used to print values of their specified types without
// initializing an instance of the class.
#include <iostream>
#include <cmath>
#include "./../FloatUnion.hpp"
#include "./../HomeworkAssignment_1.cpp"

int main()
{
	HomeworkAssignment_1::printChar( 'c' );
	HomeworkAssignment_1::printShort( 5 );
	HomeworkAssignment_1::printFloat( 100.2 );

	std::cout << std::endl;

	return 0;
}
