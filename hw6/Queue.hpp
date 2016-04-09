#ifndef QUEUE_HPP
#define QUEUE_HPP

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
        
        NodePointer myFront, myBack;
    public:
        Queue();
        Queue( const Queue &original );
        ~Queue();
        const Queue &operator=( const Queue &rightHandSide );
        bool empty() const;
        void enqueue( const QueueElement &value );
        void display( std::ostream &out ) const;
        QueueElement front() const;
        void dequeue();
};

#endif
