#include <iostream>
#include "linklist.h"
#include "bst.h"
#include "getData.h"
#include "Sort.h"
using std::cout;using std::endl;

int main(){
//	int z[] = {3,2,5,4,6,1,9};
	int z[] = {9,8,7,6,5,4,3,2,1};
	int l = sizeof(z)/sizeof(z[0]);
	//std::cout<<partition(z,0,4)<<std::endl;
	quickSort(z,0,l-1);
	for(int i=0;i<l;i++)
		std::cout<<*(z+i)<<std::endl;
//------ input the source data --------
	//Linklist<std::string>* list = new Linklist<std::string>();
	//Linklist<int>* list = new Linklist<int>();
	//BST<int>* list = new BST<int>();
/*
	std::string filename = "data/source.txt";
	int number = ReturnCount(filename);
	std::string* source = ReturnData(filename,number);
*/
//------ create the list ------
/*	
	for(int i = 0; i<number;i++){
		list->insertNode(std::stoi(source[i]));
	}
*/
//----- the height of the tree ------
/*	
	list->inorderTraversal(list->root);
	std::cout<<"tree height is "<<list->getHeight(list->root)<<std::endl;
*/

// --- search a node -----
/*
	Node<int>* node;
	node = list->findNode(5,list->root);// recursive way
*/

// ----- find the successor node -----
/*	
	int value = 5;
	std::cout<<"successor is "<<list->successor(value)<<std::endl;
	std::cout<<"predecessor is "<<list->predecessor(value)<<std::endl;
*/


//------ delete node ------
/*
	std::cout<<"begin to delete a node"<<std::endl;
	for(int i = 0; i<number;i++)
		list->deleteNode(list->root->member);

	list->inorderTraversal(list->root);
*/

//------ test the merge sort -----
/*
	std::string x[] ={"hello","world","huang","chao"};
	int l = sizeof(x)/sizeof(x[0])-1;
	std::string* z;
	z = mergeSort(x,0,l);
	for(int i=0;i<l+1;i++)
		std::cout<<*(z+i)<<std::endl;
*/	


}

