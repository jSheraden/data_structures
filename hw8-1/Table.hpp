#ifndef TABLE_HPP
#define TABLE_HPP

#include <iostream>
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

class Table
{
    private:
        // Helper functions.
        int hash( int key ) const;
        void findIndex( int key, bool &found, int &i ) const;

        // Data members.
        RecordType table[CAPACITY];
        int used;
    public:
        Table();
        void insert( const RecordType &entry );
        void find( int key, bool &found, RecordType &result ) const;
        int size() const;
        void display() const;
        void remove( int key );
};

#endif
