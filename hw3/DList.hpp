#ifndef DLIST_HPP
#define DLIST_HPP

const int CAPACITY = 1024;
typedef int ElementType;

class DList
{
    private:
        int mySize;
        int myCapacity;
        ElementType *myArray[CAPACITY];
    public:
        DList();
        DList( int maxSize );
        bool empty() const;
        void insert( ElementType item, int pos );
        void erase( int pos );
        void display( std::ostream &out ) const;
        int getSize() const;
        int getCapacity() const;
};

std::ostream &operator<<( std::ostream &out, const DList &aList );

#endif
