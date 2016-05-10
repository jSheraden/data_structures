#include "Table.hpp"

// Table class constructor.
Table::Table()
{
    used = 0;

    for ( int i = 0; i < CAPACITY; i++ )
        table[i] = NULL;
}

// Table.hash()
int Table::hash( int key ) const
{
    return key % CAPACITY;
}

// Table.findPtr()
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

// Table.insert()
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

// Table.find()
void Table::find( int key, bool &found, RecordType &result ) const
{
    Node *nodePtr;

    assert( key >= 0 );

    findPtr( key, found, nodePtr );

    if ( found )
        result = nodePtr->rec;
}

// Table.size()
int Table::size() const
{
    return used;
}

// Table.display()
void Table::display() const
{
    std::cout << "\nThe hash table is: " << std::endl;
    std::cout << "\nIndex  Key    Data" << std::endl;

    for ( int i = 0; i < CAPACITY; i++ )
    {
        if ( table[i] != 0 )
        {
            std::cout << std::setw( 5 ) << i << std::setw( 5 ) << table[i]->rec.key;

            if ( table[i]->rec.key != 0 )
                std::cout << std::setw( 8 ) << table[i]->rec.data;

            std::cout << std::endl;
        }
    }
}

// Table.erase()
void Table::erase( int key )
{

}
