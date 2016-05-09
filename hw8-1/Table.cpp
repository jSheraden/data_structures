#include "Table.hpp"

// Table class constructor.
Table::Table()
{
    used = 0;

    for ( int i = 0; i < CAPACITY; i++ )
        table[i].key = -1;
}

// Table.hash() - this function is used to determine
// the table array index of a given key.
int Table::hash( int key ) const
{
    return key % CAPACITY;
}

// Table.findIndex() - find the index if a given value
// in the hash table.
void Table::findIndex( int key, bool &found, int &i ) const
{
    int count = 0;

    assert( key >= 0 );

    i = hash( key );
    while ( count < CAPACITY && table[i].key != -1 && table[i].key != key )
    {
        count++;
        i = ( i + 1 ) % CAPACITY;
    }

    found = ( table[i].key == key );
}

// Table.insert() - insert a value into the hash table.
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

// Table.find() - determine if the record at a
// given key in the table has been assigned a
// data value.
void Table::find( int key, bool &found, RecordType &result ) const
{
    int index;

    assert( key >= 0 );

    findIndex( key, found, index );

    if ( found )
        result = table[index];
}

// Table.size() - returns the number of items
// currently in the hash table.
int Table::size() const
{
    return used;
}

// Table.display() - displays the hash table.
void Table::display() const
{
    std::cout << "\nThe hash table is: " << std::endl;
    std::cout << "\nIndex  Key    Data" << std::endl;

    for ( int i = 0; i < CAPACITY; i++ )
    {
        std::cout << std::setw( 5 ) << i << std::setw( 5 ) << table[i].key;

        if ( table[i].key != -1 )
            std::cout << std::setw( 8 ) << table[i].data;

        std::cout << std::endl;
    }
}

// Table.remove() - remove an item from
// the hash table.
void Table::remove( int key )
{
    if ( key < 0 || key > 31 )
        std::cout << "\nThat value is not in the table." << std::endl;
    else
    {
        RecordType reset;
        reset.key = -1;
        reset.data = 0;
        table[key] = reset;
    }
}
