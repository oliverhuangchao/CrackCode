#include <iostream>
#include "linklist.h"
//#include "node.h"
//#include "test.h"

using std::cout;using std::endl;

int main(){
	Linklist<int>* list = new Linklist<int>();
	int x = 10;
	int y = 5;
	int z = 7;
	list->insertNode(x);
	list->insertNode(y);
	list->insertNode(z);
	list->print();
}

