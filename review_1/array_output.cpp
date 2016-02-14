#include <iostream>

int main()
{
	int list[5] = { 10, 20, 30, 40, 50 };

	// What will this print?
	std::cout << *(list + 2) << std::endl;

	return 0;
}
