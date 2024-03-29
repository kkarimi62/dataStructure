#include "treenode.h"

#ifndef TREE_H
#define TREE_H

template< class NODETYPE >
class Tree
//--- implementation for binary tree
{
	public:
		Tree();
		void insertNode( const NODETYPE & );
		void preOrderTraversal() const;
	private:
		TreeNode< NODETYPE > *rootPtr;
		void insertNodeHelper( TreeNode< NODETYPE >* &, TreeNode< NODETYPE > * );
		void preOrderTraversalHelper( TreeNode< NODETYPE >* ) const;
};
//constructor
template< class NODETYPE >
Tree< NODETYPE >::Tree():rootPtr( 0 ){}
// public member function for node insertion
template< class NODETYPE >
void Tree< NODETYPE >::insertNode( const NODETYPE &data )
{
	TreeNode< NODETYPE > *nodePtr = new TreeNode< NODETYPE >( data ); //create node
	insertNodeHelper( rootPtr, nodePtr );
}
//utility function 
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
//utility function
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
