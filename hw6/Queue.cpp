#include "Queue.hpp"

// The main constructor.
Queue::Queue() : myFront( 0 ), myBack( 0 ) {}

// Overloaded constructor.
Queue::Queue( const Queue &original )
{
    myFront = myBack = 0;
    
    if ( !original.empty() )
    {
        // Copy first node.
        myFront = myBack = new Queue::Node( original.front() );
        
        // Set pointer to run through original's linked list.
        Queue::NodePointer origPtr = original.myFront->next;
        
        while ( origPtr != 0 )
        {
            myBack->next = new Queue::Node( origPtr->data );
            myBack = myBack->next;
            origPtr = origPtr->next;
        }
    }
}

// Destructor.
Queue::~Queue()
{
    // Set pointer to run through the queue.
    Queue::NodePointer prev = myFront, ptr;
    
    while ( prev != 0 )
    {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
}

// Assignment operator.
const Queue &Queue::operator=( const Queue &rightHandSide )
{
    // Check that q != q.
    if ( this != &rightHandSide )
    {
        this->~Queue();   // Destroy current linked list.
        
        if ( rightHandSide.empty() )
        {
            myFront = myBack = 0;
        }
        else
        {
            // Copy first node.
            myFront = myBack = new Queue::Node( rightHandSide.front() );
            
            // Set pointer to run through rightHandSide's linked list.
            Queue::NodePointer rhsPtr = rightHandSide.myFront->next;
            
            while ( rhsPtr != 0 )
            {
                myBack->next = new Queue::Node( rightHandSide.front() );
                myBack = myBack->next;
                rhsPtr = rhsPtr->next;
            }
        }
    }
    
    return *this;
}


// Queue.empty() - Determine if the queue is empty or not.
bool Queue::empty() const
{
    return ( myFront == 0 );
}

// Queue.enqueue()
void Queue::enqueue( const QueueElement &value );
{
    Queue::NodePointer newPtr = new Queue::Node( value );
    
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

// Queue.display() - Print each element in the queue.
void Queue::display( std::ostream &out ) const
{
    Queue::NodePointer ptr;
    
    for ( ptr = myFront; ptr != 0; ptr = ptr->next )
    {
        out << ptr->data << " ";
    }
    
    out << end;
}

// Queue.front()
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

// Queue.dequeue()
void dequeue()
{
    if ( !empty() )
    {
        Queue::NodePointer ptr = myFront;
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
