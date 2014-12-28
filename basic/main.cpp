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
	//list->findMin();
	//list->findMax();
	list->inorderTraversal(list->root);

//	std::cout<<list->findNode(5)<<std::endl;
	Node<int>* node = list->findNode(5,list->root);
	if(node == nullptr) std::cout<<"do not find it"<<std::endl;
	else std::cout<<"find it!!!"<<std::endl;

	/*
	cout<<"begin to delete"<<endl;
	list->deleteNode(1);
	list->print();
	cout<<"begin to clear"<<endl;
	list->clear();
	list->print();
*/
}

