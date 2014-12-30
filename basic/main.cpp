#include <iostream>
#include "linklist.h"
#include "bst.h"
#include "getData.h"
using std::cout;using std::endl;

int main(){
//------ input the source data --------
	//Linklist<std::string>* list = new Linklist<std::string>();
	//Linklist<int>* list = new Linklist<int>();
	BST<int>* list = new BST<int>();

	std::string filename = "data/source.txt";
	int number = ReturnCount(filename);
	std::string* source = ReturnData(filename,number);


//------ create the list ------
	for(int i = 0; i<number;i++){
		list->insertNode(std::stoi(source[i]));
	}
	list->inorderTraversal(list->root);


	Node<int>* node;
// --- search a node -----
//	std::cout<<list->findNode(5)<<std::endl;// iteration way
	node = list->findNode(5,list->root);// recursive way
	//if(node == nullptr) std::cout<<"do not find it"<<std::endl;
	//else std::cout<<"find it!!!"<<std::endl;

// ----- find the successor node -----
//	int value = 5;
//	std::cout<<"successor is "<<list->successor(value)<<std::endl;
//	std::cout<<"predecessor is "<<list->predecessor(value)<<std::endl;



//------ delete node ------
	std::cout<<"begin to delete a node"<<std::endl;
	list->deleteNode(17);
	list->inorderTraversal(list->root);
/*
	cout<<"begin to delete"<<endl;
	list->deleteNode(1);
	list->print();
	cout<<"begin to clear"<<endl;
	list->clear();
	list->print();
*/
}

