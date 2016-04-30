#include <new>
#include "Stack.hpp"

// Definition of Stack constructor.
Stack::Stack() : myTop( 0 ) {}

Stack::Stack( const Stack &original )
{
    myTop = 0;

    if ( !original.empty() )
    {
        // Copy first node.
        myTop = new Node( original.top() );

        // Set pointers to run through the stack's linked lists.
        NodePointer lastPtr = myTop;
        NodePointer origPtr = original.myTop->next;

        while ( origPtr != 0 )
        {
            lastPtr->next = new Node( origPtr->data );
            lastPtr = lastPtr->next;
            origPtr = origPtr->next;
        }
    }
}

Stack::~Stack()
{

}

const Stack &Stack::operator=( const Stack &rightHandSide )
{

}

bool Stack::empty() const
{

}

void Stack::push( const StackElement &value )
{

}

void Stack::display( std::ostream &out ) const
{

}

StackElement Stack::top() const
{

}

void Stack::pop()
{

}
