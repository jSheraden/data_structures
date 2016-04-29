#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

// Alias for stack items.
typedef int StackElement;

class Stack
{
    private:
        // Node class.
        class Node
        {
            public:
                StackElement data;
                Node *next;

                // Node class constructor.
                Node( StackElement value, Node *link = 0 ) : data( value ), next( link ) {}
        };

        // Node class pointer alias.
        typedef Node * NodePointer;

        // Pointer to top of stack.
        NodePointer myTop;
    public:
        // Stack class constructor.
        Stack( const Stack &original );

        // Stack class destructor.
        ~Stack();

        // Assignment operator.
        const Stack &operator=( const Stack &rightHandSide );

        // Stack.empty() - determines if there are items
        // in the stack.
        bool empty() const;

        // Stack.push() - adds a new item to the stack.
        void push( const StackElement &value );

        // Stack.display() - print the stack to the console.
        void display( std::ostream &out ) const;

        // Stack.top() - returns the item at the top of
        // the stack.
        StackElement top() const;

        // Stack.pop() - removes the item at the top of
        // the stack.
        void pop();
};

#endif
