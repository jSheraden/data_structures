#include <iostream>

int main()
{
    int i = 5;
    int j = 8;
    int *ptr1 = &i;
    int *ptr2 = &j;
    
    std::cout << *ptr1 << std::endl;
    std::cout << *ptr2 << std::endl;
    
    return 0;
}