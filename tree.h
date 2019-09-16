#include "treenode.h"

#ifndef TREE_H
#define TREE_H

template< class NODETYPE >
class Tree
{
	public:
		Tree();
		void insertNode( const NODETYPE & );
		void preOrderTraversal() const;
//		void inOrderTraversal() const;
//		void postOrderTraversal() const;
	private:
		TreeNode< NODETYPE > *rootPtr;
		void insertNodeHelper( TreeNode< NODETYPE >* &, TreeNode< NODETYPE > * );
		void preOrderTraversalHelper( TreeNode< NODETYPE >* ) const;
//		void preOrderHelper( const NODETYPE & );
};
//constructor
template< class NODETYPE >
Tree< NODETYPE >::Tree():rootPtr( 0 ){}
//
template< class NODETYPE >
void Tree< NODETYPE >::insertNode( const NODETYPE &data )
{
	TreeNode< NODETYPE > *nodePtr = new TreeNode< NODETYPE >( data ); //create node
	insertNodeHelper( rootPtr, nodePtr );
}
//
template< class NODETYPE >
void Tree< NODETYPE >::insertNodeHelper( TreeNode< NODETYPE >* &ptr, TreeNode< NODETYPE > *nodePtr )
{
	if( ptr == 0 )
		ptr = nodePtr;
	else
	{
		if( nodePtr->data < ptr->data )
			insertNodeHelper( ptr->leftPtr, nodePtr );
		else
		{
			if( nodePtr->data > ptr->data )
				insertNodeHelper( ptr->rightPtr, nodePtr );
			else 
			{
				assert( nodePtr->data == ptr->data );
				printf("duplicate!\n");
			}
		}

	}	
}
//
template< class NODETYPE >
void Tree< NODETYPE >::preOrderTraversal() const
{
	preOrderTraversalHelper( rootPtr );
	
}

template< class NODETYPE >
void Tree< NODETYPE >::preOrderTraversalHelper( TreeNode< NODETYPE > *ptr ) const
{
	if ( ptr != 0 )
	{
		preOrderTraversalHelper( ptr->leftPtr );
		printf("%d\n",ptr->data);
		preOrderTraversalHelper( ptr->rightPtr );
	}
}
#endif
