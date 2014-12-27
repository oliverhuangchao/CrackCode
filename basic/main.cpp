#include <iostream>
#include "linklist.h"
//#include "node.h"
//#include "test.h"

using std::cout;using std::endl;

int main(){
	Linklist<float>* list = new Linklist<float>();
	float x[5]={5.6,1.2,3.5,4.6,2.5};
	for(int i = 0; i<5;i++)
		list->insertNode(x[i]);
	list->print();
	cout<<"begin to delete"<<endl;
	list->deleteNode(1);
	list->print();
	cout<<"begin to search"<<endl;
	cout<<list->findNode(2.5)<<endl;
	cout<<"begin to clear"<<endl;
	list->clear();
	list->print();
}

