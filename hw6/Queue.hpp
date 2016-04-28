#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

typedef int QueueElement;

class Queue
{
    private:
        class Node
        {
            public:
                QueueElement data;
                Node *next;
                Node( QueueElement value, Node *link = 0 ) : data( value ), next( link ) {}
        };

        typedef Node * NodePointer;

        NodePointer myBack;
    public:
        // The main constructor.
        Queue();

        // The class has no copy constructor.
        Queue( const Queue &original );

        // Destructor.
        ~Queue();

        // Queue.empty() - Determine if the queue is empty or not.
        bool empty() const;

        // Queue.enqueue()
        void enqueue( const QueueElement &value );

        // Queue.display() - Print each element in the queue.
        void display( std::ostream &out ) const;

        // Queue.front()
        QueueElement front() const;

        // Queue.dequeue()
        void dequeue();

        // The class has no assignment operator.
        const Queue &operator=( const Queue &rightHandSide );
};

#endif
