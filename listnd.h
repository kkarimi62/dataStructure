

#ifndef LISTND_H 
#define LISTND_H 

template< class NODETYPE > class List; //forward declaration


template< class NODETYPE >
class listNode
{
	friend class List< NODETYPE >; //list class is a friend
	public:
		listNode( const NODETYPE &); //constructor
//		~listNode();
		NODETYPE getData() const; //return node data
	private:
		NODETYPE data;
		listNode< NODETYPE > *nextPtr;
};
//default constructor
template< class NODETYPE >
listNode< NODETYPE >::listNode( const NODETYPE &dataa )
:data( dataa ), nextPtr( 0 )
{}
//
template< class NODETYPE >
NODETYPE listNode< NODETYPE >::getData() const
{
	return data;	
}
#endif

