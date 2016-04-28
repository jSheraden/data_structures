#include "Queue.hpp"

Queue::Queue() : myBack( 0 ) {}

Queue::~Queue()
{
    // Set pointer to run through the queue.
    NodePointer prev = myBack, ptr;

    /*while ( prev != 0 )
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
    NodePointer ptr;

    // Print the queued nodes. It skips the last node
    // for some reason.
    for ( ptr = myBack; ptr->next != ptr; ptr = ptr->next )
    {
        out << ptr->data << " ";
    }

    // Print the last node.
    out << ptr->data << std::endl;
}

QueueElement Queue::front() const
{
    if ( empty() )
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
