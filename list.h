#include "listnd.h"
#include <stdio.h>
#include <assert.h>

#ifndef LIST_H
#define LIST_H

template< class NODETYPE >
class List
{
	public:
		List(); //constructor
//		~List(); //deconstructor
		void insertAtFront( const NODETYPE & ); //member functions
		void insertAtBack( const NODETYPE & );
		void removeFromFront(); // const NODETYPE & );
		void removeFromBack(); // const NODETYPE & );
		void Print();
	private:
		listNode< NODETYPE > *firstPtr; //ptr to first node
		listNode< NODETYPE > *lastPtr; //ptr to last node
		listNode< NODETYPE > *newPtr; //ptr to new node
		listNode< NODETYPE > * getNewNode( const NODETYPE & ); //new node
		bool isEmpty() const; //return true or false
		listNode< NODETYPE >* NextToLast() const;
};
//constructor
template< class NODETYPE >
List< NODETYPE >::List():firstPtr( 0 ), lastPtr( 0 ){}

//destructor
//template< class NODETYPE >
//List< NODETYPE >::~List()
//{
//	delete newPtr;
//{
//insertion at front
template< class NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &data )
{
	listNode< NODETYPE > *newPtr = getNewNode( data ); //new node with data
	if( isEmpty() ) //if empty
	{
		firstPtr = lastPtr = newPtr; //set firstPtr & lastPtr to newPtr
	}
	else //if not empty
	{
		listNode< NODETYPE > *tmpPtr = firstPtr;
		firstPtr = newPtr;
		newPtr->nextPtr = tmpPtr;
	}	
}
//insertion at back
template< class NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &data )
{
	listNode< NODETYPE > *newPtr = getNewNode( data ); //new node with data
	if( isEmpty() ) //if empty
	{
		firstPtr = lastPtr = newPtr; //set firstPtr & lastPtr to newPtr
	}
	else //if not empty
	{
		listNode< NODETYPE > *tmpPtr = lastPtr;
		lastPtr = newPtr;
		tmpPtr->nextPtr = newPtr;
	}	
}
//remove at front
template< class NODETYPE >
void List< NODETYPE >::removeFromFront()
{
	if( isEmpty() ) //if empty
	{
		return;
	}
	else //if not empty
	{
		listNode< NODETYPE > *tmpPtr = firstPtr; //save before updating
		firstPtr = firstPtr->nextPtr;
		delete tmpPtr; //delete 
	}	
}
//next-to-last node
template< class NODETYPE >
listNode< NODETYPE >* List< NODETYPE >::NextToLast() const
{
	listNode< NODETYPE > *tmpPtr = firstPtr;
	while( tmpPtr->nextPtr != lastPtr )
		tmpPtr = tmpPtr->nextPtr;
	assert( tmpPtr->nextPtr == lastPtr );
	return tmpPtr; 
}
//remove at back
template< class NODETYPE >
void List< NODETYPE >::removeFromBack()
{
	if( isEmpty() ) //if empty
	{
		return;
	}
	else //if not empty
	{
		if( firstPtr == lastPtr )
		{
			delete firstPtr;
			firstPtr = lastPtr = 0;
		}
		else
		{
			listNode< NODETYPE > *tmpPtr = lastPtr; //save before updating
			//--- find next to last node
			lastPtr = NextToLast();
			lastPtr->nextPtr = 0;
			delete tmpPtr; //delete 
		}
	}	
	return;
}
//allocate new node
template< class NODETYPE >
listNode< NODETYPE >* List< NODETYPE >::getNewNode( const NODETYPE &data )
{
	listNode< NODETYPE > *newPtr = new listNode< NODETYPE >( data );
	assert( newPtr != 0 );
	return newPtr;
}
//print
template< class NODETYPE >
void List< NODETYPE >::Print()
{
	listNode< NODETYPE > *tmpPtr = firstPtr;
	while( tmpPtr != 0 )
	{
		printf( "%f\t",tmpPtr->data );
		tmpPtr = tmpPtr->nextPtr;
	}
	printf("\n");
	assert( tmpPtr == 0 ); 
}
// empty list
template< class NODETYPE >
bool List< NODETYPE >::isEmpty() const { return firstPtr == 0; }
//
#endif
