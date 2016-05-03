// Name: Joseph Sheraden
// Project Number: 7
// Project Description: Binary Search Tree
// Course: Data Structures
// Instructor: Bob Comer
// Date: May 3, 2016
#include <iostream>
#include <iomanip>
#include <new>
#include "BST.cpp"  // Included .cpp file instead of .hpp, turns out
                    // C++ doesn't allow template classes to be
                    // imported from multiple files.

int main()
{
    BST<int> bst;
    std::cout << "Success!" << std::endl;
    return 0;
}
