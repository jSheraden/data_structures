#ifndef DLIST_HPP
#define DLIST_HPP

const int CAPACITY = 1024;
typedef int ElementType;

class DList
{
    private:
        int mySize;
        ElementType myArray[CAPACITY];
    public:
        DList();
        bool empty() const;
        void insert( ElementType item, int pos );
        void erase( int pos );
        void display( std::ostream &out ) const;
};

#endif
