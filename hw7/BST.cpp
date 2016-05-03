#include "BST.hpp"

// BST class constructor.
template <typename DataType>
inline BST<DataType>::BST() : myRoot( 0 ) {}

// BST.empty()
template <typename DataType>
inline bool BST<DataType>::empty() const
{
    return ( myRoot == 0 );
}

// BST.search()
template <typename DataType>
bool BST<DataType>::search( const DataType &item ) const
{
    BinNodePointer locPtr = myRoot;
    bool found = false;

    while ( !found && !locPtr = 0 )
    {
        if ( item < locPtr->data )      // Descend left.
            locPtr = locPtr->left;
        else if ( locPtr->data < item ) // Descend right.
            locPtr = locPtr->right;
        else                            // Item found.
            found = true;
    }

    return found;
}

// BST.insert()
template <typename DataType>
void BST<DataType>::insert( const DataType &item )
{
    BinNodePointer locPtr = myRoot; // Search pointer.
    BinNodePointer parent = 0;      // Pointer to parent of current node.
    bool found = false;             // Indicates of item is already in tree.

    while ( !found && !locPtr == 0 )
    {
        parent = locPtr;

        if ( item < locPtr->data )      // Descend left.
            locPtr = locPtr->left;
        else if ( locPtr->data < item ) // Descend right.
            locPtr = locPtr->right;
        else                            // Item found.
            found = true;
    }

    if ( !found )
    {
        // Construct node containing item.
        locPtr = new BinNode( item );

        if ( parent == 0 )              // Empty tree.
            myRoot = locPtr;
        else if ( item < parent->data ) // Insert to left of parent.
            parent->left = locPtr;
        else                            // Insert to right of parent.
            parent->right = locPtr;
    }
    else
        std::cout << "Item already in tree." << std::endl;
}

// BST.remove()
template <typename DataType>
inline void BST<DataType>::remove( const DataType &item )
{

}

// BST.inOrder()
template <typename DataType>
inline void BST<DataType>::inOrder( std::ostream &out ) const
{

}

// BST.graph()
template <typename DataType>
inline void BST<DataType>::graph( std::ostream &out ) const
{

}

// BST.search2()
template <typename DataType>
inline void BST<DataType>::search2( const DataType &item, bool &found, BinNodePointer &locPtr, BinNodePointer &parent ) const
{

}

// BST.inOrderAux()
template <typename DataType>
inline void BST<DataType>::inOrderAux( std::ostream &out, BinNodePointer subTreePtr ) const
{

}

// BST.graphAux()
template <typename DataType> inline
void BST<DataType>::graphAux( std::ostream &out, int indent, BinNodePointer subTreeRoot ) const
{

}
