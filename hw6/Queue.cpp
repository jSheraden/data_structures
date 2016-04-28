#include "Queue.hpp"

Queue::Queue() : myBack( 0 ) {}

Queue::~Queue()
{
    // NodePointer temp = 0;
    NodePointer current = myBack;

    while ( current->next != current )
    {
        delete current;
        current = current->next;
    }
    /*
    while ( current )
    {
        temp = current;
        current = current->next;

        delete temp;
    }
    */

    /*
    NodePointer prev = myBack;
    NodePointer ptr;

    while ( prev )
    {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
    */
}

bool Queue::empty() const
{
    return ( myBack == 0 );
}

void Queue::enqueue( const QueueElement &value )
{
    NodePointer newPtr = new Queue::Node( value );

    if ( empty() )
    {
        myBack = newPtr;
        myBack->next = myBack;
    }
    else
    {
        newPtr->next = myBack;
        myBack = newPtr;
    }
}

void Queue::display( std::ostream &out ) const
{
    NodePointer current = myBack;

    // Print the queued nodes. It skips the last node
    // for some reason.
    while ( current->next != current )
    {
        out << current->data << " ";
        current = current->next;
    }

    // Print the last node.
    out << current->data << std::endl;
}

QueueElement Queue::front() const
{
    if ( !empty() )
    {
        return myBack->data;
    }
    else
    {
        std::cerr << "*** Queue is empty -- returning garbage ***\n";

        QueueElement *temp = new( QueueElement );
        QueueElement garbage = *temp;

        delete temp;

        return garbage;
    }
}

void Queue::dequeue()
{
    if ( !empty() )
    {
        NodePointer ptr = myBack;

        myBack = myBack->next;

        delete ptr;

        if ( myBack->next == 0 )
        {
            myBack = 0;
        }
    }
    else
    {
        std::cerr << "*** Queue is empty -- can't remove a value ***\n";
    }
}
