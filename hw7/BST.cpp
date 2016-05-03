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
        if ( item < locPtr->data )
            locPtr = locPtr->left;
        else if ( locPtr->data < item )
            locPtr = locPtr->right;
        else
            found = true;
    }
}

// BST.insert()
template <typename DataType>
inline void BST<DataType>::insert( const DataType &item )
{

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
