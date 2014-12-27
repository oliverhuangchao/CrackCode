#include <iostream>
#include "linklist.h"
#include "getData.h"
using std::cout;using std::endl;

int main(){
//------ input the source data --------
	Linklist<std::string>* list = new Linklist<std::string>();
	std::string filename = "data/source.txt";
	int number = ReturnCount(filename);
	std::string* source = ReturnData(filename,number);
//------ create the list ------
	for(int i = 0; i<number;i++)
		list->insertNode((source[i]));
	list->print();
	cout<<"begin to delete"<<endl;
	list->deleteNode(1);
	list->print();
	cout<<"begin to search"<<endl;
	list->clear();
	list->print();
}

