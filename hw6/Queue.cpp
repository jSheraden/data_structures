#include "Queue.hpp"

Queue::Queue() : myFront( 0 ), myBack( 0 ) {}

Queue::~Queue()
{
    // Set pointer to run through the queue.
    NodePointer prev = myFront, ptr;

    while ( prev != 0 )
    {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
}

bool Queue::empty() const
{
    return ( myFront == 0 );
}

void Queue::enqueue( const QueueElement &value )
{
    NodePointer newPtr = new Queue::Node( value );

    if ( empty() )
    {
        myFront = myBack = newPtr;
    }
    else
    {
        myBack->next = newPtr;
        myBack = newPtr;
    }
}

void Queue::display( std::ostream &out ) const
{
    NodePointer ptr;

    for ( ptr = myFront; ptr != 0; ptr = ptr->next )
    {
        out << ptr->data << " ";
    }

    out << std::endl;
}

QueueElement Queue::front() const
{
    if ( empty() )
    {
        return myFront->data;
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
        NodePointer ptr = myFront;
        myFront = myFront->next;

        delete ptr;

        if ( myFront == 0 )
        {
            myBack = 0;
        }
    }
    else
    {
        std::cerr << "*** Queue is empty -- can't remove a value ***\n";
    }
}
