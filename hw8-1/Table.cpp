#include "Table.hpp"

// Table class constructor.
Table::Table()
{
    used = 0;

    for ( int i = 0; i < CAPACITY; i++ )
        table[i].key = -1;
}

// Table.hash()
int Table::hash( int key ) const
{
    return key % CAPACITY;
}

// Table.findIndex()
void Table::findIndex( int key, bool &found, int &i ) const
{

}

// Table.insert()
void Table::insert( const RecordType &entry )
{
    bool alreadyThere;
    int index;

    assert( entry.key >= 0 );

    findIndex( entry.key, alreadyThere, index );

    if ( alreadyThere )
        table[index] = entry;
    else
    {
        assert( size() < CAPACITY );
        index = hash( entry.key );

        while ( table[index].key != -1 )
            index = ( index + 1 ) % CAPACITY;

        table[index] = entry;
        used++;
    }
}

// Table.find()
void Table::find( int key, bool &found, RecordType &result ) const
{

}

// Table.size()
int Table::size() const
{
    return used;
}
