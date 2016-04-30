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

// Definition of Stack destructor.
Stack::~Stack()
{
    // Set pointers to run through the stack.
    NodePointer currPtr = myTop; // Node to be deallocated.
    NodePointer nextPtr;         // Its successor.

    while ( currPtr != 0 )
    {
        nextPtr = currPtr->next;
        delete currPtr;
        currPtr = nextPtr;
    }
}

// Definition of Stack assignment operator.
const Stack &Stack::operator=( const Stack &rightHandSide )
{
    // Check that st != st.
    if ( this != rightHandSide )
    {
        // Destroy current linked list.
        this->~Stack();

        // If the stack is empty.
        if ( rightHandSide.empty() )
        {
            myTop = 0;
        }

        // If not, copy rightHandSide's list.
        else
        {
            // Copy first node.
            myTop = new Node( rightHandSide.top() );

            // Set pointers to run through the stack's linked lists.
            NodePointer lastPtr = myTop
            NodePointer rhsPtr = rightHandSide.myTop->next;

            while ( rhsPtr != 0 )
            {
                lastPtr->next = new Node( rhsPtr->data );
                lastPtr = lastPtr->next;
                rhsPtr = rhsPtr->next;
            }
        }
    }

    return *this;
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
