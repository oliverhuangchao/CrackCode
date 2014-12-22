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

	Linklist();
	//Linklist(const Linklist&);

	Node<T>* getNode(int order);
	void insertNode(T val);
	void deleteNode(T val);
	void deleteNode(int order);
	void clear();
	void sortNode();
	void print();

};

#endif
