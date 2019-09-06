#include "listnd.h"
#include "list.h"
#include <stdio.h>

int main()
{
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
		
	
	return 0;
}
