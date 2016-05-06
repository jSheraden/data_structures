#include "BST.hpp"

// BST class constructor.
template <typename DataType>
inline BST<DataType>::BST() : myRoot( 0 ) {}

// BST.empty() - determine if the binary search tree
// is empty or not.
template <typename DataType>
inline bool BST<DataType>::empty() const
{
    return ( myRoot == 0 );
}

// BST.search() - determine if a specific value is in
// the binary search tree.
template <typename DataType>
bool BST<DataType>::search( const DataType &item ) const
{
    BinNodePointer locPtr = myRoot;
    bool found = false;

    while ( !found && locPtr != 0 )
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

// BST.insert() - insert a value into the binary search tree.
template <typename DataType>
void BST<DataType>::insert( const DataType &item )
{
    BinNodePointer locPtr = myRoot; // Search pointer.
    BinNodePointer parent = 0;      // Pointer to parent of current node.
    bool found = false;             // Indicates if item is already in tree.

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

// BST.remove() - remove a node from the binary search tree.
template <typename DataType>
void BST<DataType>::remove( const DataType &item )
{
    bool found;             // Signals if item is found.
    BinNodePointer temp;    // Points to node to be deleted.
    BinNodePointer parent;  // Parent of temp and tempSucc.

    search2( item, found, temp, parent );

    if ( !found )
    {
        std::cout << "Item not in the binary search tree." << std::endl;
        return;
    }

    if ( temp->left != 0 && temp->right != 0 )
    {
        // Node has 2 children, find temp's inOrder successor
        // and its parent.
        BinNodePointer tempSucc = temp->right;
        parent = temp;

        while ( tempSucc->left != 0 )   // Descend left.
        {
            parent = tempSucc;
            tempSucc = tempSucc->left;
        }

        // Move contents of tempSucc to temp and change temp
        // to point to successor, which will be removed.
        temp->data = tempSucc->data;
        temp = tempSucc;
    }   // End if node has 2 children.

    // Now proceed with case where node has 0 of 1 child.
    BinNodePointer subtree = temp->left;    // Pointer to a subtree of temp.

    if ( subtree == 0 )
        subtree = temp->right;

    if ( parent == 0 )                      // Root being removed.
        myRoot = subtree;
    else if ( parent->left == temp )        // Left child of parent.
        parent->left = subtree;
    else
        parent->right = subtree;            // Right child of parent.

    delete temp;
}

// BST.inOrder() - calls the inOrderAux() function
// to display the nodes in the tree.
template <typename DataType>
inline void BST<DataType>::inOrder( std::ostream &out ) const
{
    inOrderAux( out, myRoot );
}

// BST.graph() - calls the graphAux() function to display
// the binary search tree.
template <typename DataType>
inline void BST<DataType>::graph( std::ostream &out ) const
{
    graphAux( out, 0, myRoot );
}

// BST.search2() - search for a specific value in the
// binary search tree.
template <typename DataType>
void BST<DataType>::search2( const DataType &item, bool &found, BinNodePointer &locPtr, BinNodePointer &parent ) const
{
    locPtr = myRoot;
    parent = 0;
    found = false;

    while ( !found && locPtr != 0 )
    {
        if ( item < locPtr->data )      // Descend left.
        {
            parent = locPtr;
            locPtr = locPtr->left;
        }
        else if ( locPtr->data < item ) // Descend right.
        {
            parent = locPtr;
            locPtr = locPtr->right;
        }
        else                            // Item found.
            found = true;
    }
}

// BST.inOrderAux() - print every value in the binary
// search tree in ascending order.
template <typename DataType>
inline void BST<DataType>::inOrderAux( std::ostream &out, BinNodePointer subtreePtr ) const
{
    if ( subtreePtr != 0 )
    {
        inOrderAux( out, subtreePtr->left );   // Left operation.
        out << subtreePtr->data << " ";        // V operation.
        inOrderAux( out, subtreePtr->right );  // Right operation.
    }
}

// BST.graphAux() - print the binary search tree.
template <typename DataType>
void BST<DataType>::graphAux( std::ostream &out, int indent, BinNodePointer subtreeRoot ) const
{
    if ( subtreeRoot != 0 )
    {
        graphAux( out, indent + 8, subtreeRoot->right );
        out << std::setw( indent ) << " " << subtreeRoot->data << std::endl;
        graphAux( out, indent + 8, subtreeRoot->left );
    }
}

// BST.height() - calls the findHeight() function
// to get the height of the tree.
template <typename DataType>
int BST<DataType>::height()
{
    BinNodePointer ptr = myRoot;
    return findHeight( ptr );
}

// BST.leafCount() - calls the findLeafCount() function
// to get the total number of nodes in the tree.
template <typename DataType>
int BST<DataType>::leafCount()
{
    BinNodePointer ptr = myRoot;
    return findLeafCount( ptr );
}

// BST.findHeight() - returns the height of the binary search tree
// from myRoot to the deepest node.
template <typename DataType>
int BST<DataType>::findHeight( BinNodePointer ptr )
{
    if ( ptr == 0 ) return -1;

    int leftHeight = findHeight( ptr->left );
    int rightHeight = findHeight( ptr->right );

    if ( leftHeight > rightHeight )
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

// BST.findLeafCount() - returns the total number of nodes in the
// binary search tree.
template <typename DataType>
int BST<DataType>::findLeafCount( BinNodePointer ptr )
{
    if ( ptr == 0 )
        return 0;
    else
        if ( ptr->left == 0 && ptr->right == 0 )
            return 1;
        else
            return 1 + findLeafCount( ptr->left ) + findLeafCount( ptr->right );
}
