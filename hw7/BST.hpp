#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <iomanip>
#include <new>

template <typename DataType>
class BST
{
    private:
        class BinNode
        {
            public:
                DataType data;
                BinNode *left;
                BinNode *right;

                // BinNode constructors.
                // Default - data part is the default DataType
                // value, both links are null.
                BinNode() : left( 0 ), right( 0 ) {}

                // Explicit value - data part contains item,
                // both parts are null.
                BinNode( DataType item ) : data( item ), left( 0 ), right( 0 ) {}
        };

        // BinNode object pointer definition.
        typedef BinNode * BinNodePointer;

        // Private function members.
        void search2( const DataType &item, bool &found, BinNodePointer &locPtr, BinNodePointer &parent ) const;
        void inOrderAux( std::ostream &out, BinNodePointer subtreePtr ) const;
        void graphAux( std::ostream &out, int indent, BinNodePointer subtreeRoot ) const;
        int findHeight( BinNodePointer ptr );
        int findLeafCount( BinNodePointer ptr );

        // Private data members.
        BinNodePointer myRoot;
    public:
        // Function members.
        BST();
        bool empty() const;
        bool search( const DataType &item ) const;
        void insert( const DataType &item );
        void remove( const DataType &item );
        void inOrder( std::ostream &out ) const;
        void graph( std::ostream &out ) const;
        int height();
        int leafCount();
};

#endif
