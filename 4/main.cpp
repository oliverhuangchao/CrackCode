#include <iostream>
#include "code.h"
//using namespace std;


int main(){
	int x[] = {5,3,1,2,4,7,0};
	int l = sizeof(x)/sizeof(x[0]);
	BST<int>* bst = new BST<int>();
	for(int i=0;i<l;i++){
		bst->insertNode(x[i]);
	}
	bst->BFS(bst->root);
	//bst->inorderTraversal(bst->root);
	/*Node<int>*n1;
	Node<int>*n2;
	Node<int>*n3;

	n1 = bst->findNode(2);
	n2 = bst->findNode(4);
	n3 = firstCommon(bst,n1,n2);
	std::cout<<n3<<std::endl;*/
}
