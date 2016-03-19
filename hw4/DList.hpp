#ifndef DLIST_HPP
#define DLIST_HPP

typedef int ElementType;

class DList
{
    private:
        class Node
        {
            public:
                ElementType data;
                Node *next;
                
                Node();
                Node( ElementType initData );
        };
        
        typedef Node * NodePointer;
        
        NodePointer first;
        int mySize;
    public:
        DList();
        DList( const DList &source );
        ~DList();
        const DList &operator=( const DList &rightHandSide );
        int find( ElementType value ) const;
        bool empty() const;
        void insert( ElementType item, int pos );
        void erase( int pos );
        void display( std::ostream &out ) const;
        int getSize() const;
};

std::ostream &operator<<( std::ostream &out, const DList &aList );

#endif
