#ifndef TREENODE_H
#define TREENODE_H

template< class NODETYPE > class Tree; //forward declaration

template< class NODETYPE >
class TreeNode
{
	friend class Tree< NODETYPE >; // tree class as a friend
	public:
		TreeNode( const NODETYPE & dataa ): leftPtr( 0 ), rightPtr( 0 ), data( dataa ) {} // constructor
		NODETYPE getData() const { return data;}
	private:
		TreeNode< NODETYPE > *leftPtr;
		TreeNode< NODETYPE > *rightPtr;
		NODETYPE data;
};

#endif
