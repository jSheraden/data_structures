// Name: Joseph Sheraden
// Project Number: 6
// Project Description: Queue using a Circular Linked List
// Course: Data Structures
// Instructor: Bob Comer
// Date: April 21, 2016
#include <iostream>
#include <new>
#include "Queue.hpp"

int main()
{
    Queue queue;

    std::cout << ( queue.empty() ? "true" : "false" ) << std::endl;

    queue.dequeue();
    queue.enqueue( 5 );
    queue.enqueue( 10 );
    queue.enqueue( 15 );
    queue.enqueue( 20 );
    queue.dequeue();
    queue.display( std::cout );

    std::cout << queue.front() << std::endl;

    // queue.~Queue();

    queue.display( std::cout );

    std::cout << "Success!" << std::endl;
    return 0;
}
