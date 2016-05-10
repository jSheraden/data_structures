#include "Table.hpp"

// Table class constructor.
Table::Table()
{
    used = 0;

    for ( int i = 0; i < CAPACITY; i++ )
        table[i] = NULL;
}

// Table.hash() - this function is used to determine
// the table array index of a given key.
int Table::hash( int key ) const
{
    return key % CAPACITY;
}

// Table.findIndex() - find the index if a given value
// in the hash table.
void Table::findPtr( int key, bool &found, Node *&nodePtr ) const
{
    int i;
    Node *ptr;

    i = hash( key );
    ptr = table[i];
    found = false;

    while ( !found && ptr != NULL )
    {
        if ( key == ptr->rec.key )
        {
            found = true;
            nodePtr = ptr;
        }

        ptr = ptr->next;
    }

    if ( !found )
        nodePtr = NULL;
}

// Table.insert() - insert a record into the hash table.
void Table::insert( const RecordType &entry )
{
    bool alreadyThere;
    Node *nodePtr;

    assert( entry.key >= 0 );

    findPtr( entry.key, alreadyThere, nodePtr );

    if ( !alreadyThere )
    {
        // Get index of "bucket" where entry belongs.
        int i = hash( entry.key );

        // Insert at beginning of list.
        Node *temp = new Node;

        temp->rec = entry;  // Copy record.
        temp->next = table[i];
        table[i] = temp;
        used++;
    }
    else
    {
        // nodePtr points to existing record that
        // should be updated.
        nodePtr->rec = entry;
    }
}

// Table.find() - determine if the record at a
// given key in the table has been assigned a
// data value.
void Table::find( int key, bool &found, RecordType &result ) const
{
    Node *nodePtr;

    assert( key >= 0 );

    findPtr( key, found, nodePtr );

    if ( found )
        result = nodePtr->rec;
}

// Table.size() - returns the number of items
// currently in the hash table.
int Table::size() const
{
    return used;
}

// Table.display() - display the hash table.
void Table::display() const
{
    std::cout << "\nThe hash table is: " << std::endl;
    std::cout << "\nIndex  Key    Data" << std::endl;

    for ( int i = 0; i < CAPACITY; i++ )
    {
        if ( table[i] != 0 )
        {
            std::cout << std::setw( 5 ) << i << std::setw( 5 ) << table[i]->rec.key;

            if ( table[i]->rec.key >= 0 )
                std::cout << std::setw( 8 ) << table[i]->rec.data;

            std::cout << std::endl;
        }
    }
}

// Table.erase() - remove an item from
// the hash table.
// Preconditions: ensure that key is greater
// than 0 and less than 31.
// Postconditions: the record at the given key
// has been removed from the table. If there
// is no record at the given key, the table
// remains unchanged.
void Table::erase( int key )
{
    if ( key < 0 || key > 31 )
        std::cout << "\nThat value is not in the table." << std::endl;
    else
    {
        Node *emptyRec = NULL;
        table[key] = emptyRec;
        used--;
    }
}
