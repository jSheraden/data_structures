#ifndef DLIST_HPP
#define DLIST_HPP

typedef int ElementType;

class DList
{
    private:
        int mySize;
        int myCapacity;
        ElementType *myArray;
    public:
        DList();
        DList( int maxSize = 1024 );
        DList( const DList &origList );
        ~DList();
        const DList &operator=( const DList &rightHandSide );
        bool empty() const;
        void insert( ElementType item, int pos );
        void erase( int pos );
        void display( std::ostream &out ) const;
        int getSize() const;
        int getCapacity() const;
};

std::ostream &operator<<( std::ostream &out, const DList &aList );

#endif
