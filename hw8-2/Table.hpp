#ifndef TABLE_HPP
#define TABLE_HPP

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <iomanip>

typedef int ItemType;
const int CAPACITY = 31;

class RecordType
{
    public:
        int key;
        ItemType data;
};

class Node
{
    public:
        RecordType rec;
        Node *next;
};

class Table
{
    private:
        int hash( int key ) const;
        void findPtr( int key, bool &found, Node *&ptr ) const;

        // Data members.
        Node *table[CAPACITY];
        int used;
    public:
        Table();
        void insert( const RecordType &entry );
        void find( int key, bool &found, RecordType &result ) const;
        int size() const;
        void display() const;
        void erase( int key );
};

#endif
