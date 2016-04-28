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
    // Initialize a Queue (circular linked list) object.
    Queue queue;

    // The list should be empty at this point.
    std::cout << ( queue.empty() ? "The list is empty." : "The list is not empty." ) << std::endl;

    // What happens if I try to remove a node
    // from an empty list?
    queue.dequeue();

    // Enqueue some nodes.
    queue.enqueue( 5 );
    queue.enqueue( 10 );
    queue.enqueue( 15 );
    queue.enqueue( 20 );
    queue.enqueue( 25 );

    // Remove one node.
    queue.dequeue();

    // Print the list of nodes.
    std::cout << "Nodes: ";
    queue.display( std::cout );

    // What value does the node at the front
    // of the list have?
    std::cout << "Front node: " << queue.front() << std::endl;

    // Exit the program.
    return 0;
}
