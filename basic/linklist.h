#ifndef LINKLIST__H
#define LINKLIST__H

#include "node.h"

template <typename T>
class Linklist{
public:
	int size;
	int capacity;
	Node<T>* head;
	Node<T>* tail;

	//Linklist();
	//Linklist(const Linklist&);

	Node<T>* getNode(int);
	void insertNode(T);
	void deleteNode(T,int);
	void deleteNode(int);
	void clear();
	void sortNode();
	void print();

};

#endif
