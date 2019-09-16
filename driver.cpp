#include "listnd.h"
#include "list.h"
#include <stdio.h>
#include "treenode.h"
#include "tree.h"

int main()
{
/*	
	listNode< int > nodeObj( 3 );
	List< double > listObj;
	listObj.insertAtBack(4.0);
	listObj.insertAtBack(12.2);
	listObj.insertAtFront(1.2);
	listObj.Print();
	listObj.removeFromBack();
	listObj.Print();
	listObj.removeFromBack();
	listObj.Print();
	listObj.removeFromBack();
	listObj.Print();
	listObj.removeFromBack();
	listObj.Print();
*/
	TreeNode< int > nodeObj(2);		
	printf("data=%d\n",nodeObj.getData());
	Tree<int> treeObj;
	treeObj.insertNode( 50 );
	treeObj.insertNode( 25 );
	treeObj.insertNode( 75 );
	treeObj.insertNode( 12 );
	treeObj.insertNode( 33 );
	treeObj.insertNode( 67 );
	treeObj.preOrderTraversal();
	
	return 0;
}
