#ifndef HEAP__H
#define HEAP__H

#include "node.h"

template <typename T>
class Heap{
public:
	int size;
	int capacity;
	Node<T>* root;

	Heap();
	~Heap();
	Node<T>* getNode(int);

	void insertNode(T);
	int findNode(T);
	void deleteNode(int);
	void clear();
	void sortNode();
	void print();
};



//------ defination goes here ------
template<typename T>
Heap<T>::Heap():
	size(0),
	capacity(1),
	root(nullptr)
{
	std::cout<<"default construct Heap"<<std::endl;
}

template<typename T>
Heap<T>::~Heap(){
	std::cout<<"distruct Heap"<<std::endl;
}


template<typename T>
void Heap<T>::print(){
	if(size == 0)
		std::cout<<"list is empty"<<std::endl;
	else{
		Node<T>* tmpPtr = head;
		for(int i = 0;i<size;i++){
			std::cout<<"node "<<i<<'\t'<<tmpPtr->member<<std::endl;
			tmpPtr = tmpPtr -> next;
		}
	}
}

template<typename T>
void Heap<T>::insertNode(const T val){
	Node<T>* newNode = new Node<T>(val);

	if(size == 0)
		head = newNode;
	else{
		Node<T>* tmpPtr = head;
		for(int j = 0;j<size - 1;j++)
			tmpPtr = tmpPtr->next;
		tmpPtr->next = newNode;
		// for the insert we need to break the current Heap and insert a new one
		// assignment for tmpPtr-> next is the key part of the link list
		//tmpPtr = newNode;
	}
	newNode->next = tail;
	size++;
	if(size == capacity/2)
		capacity = capacity * 2;
}

/* delete node using order number
order: should begin from 0, keep same setting in main file
	
*/
template<typename T>
void Heap<T>::deleteNode(int order){
	if(order > size || order <= 0) std::cout<<"out of list member"<<std::endl;
	Node<T>* tmpPtr = head;
	for (int i = 0;i < order - 1; i++){
		tmpPtr = tmpPtr -> next;
	}
	Node<T>* tryDeletePtr = tmpPtr->next;
	tmpPtr->next = tryDeletePtr->next;
	size--;
	if(size < capacity/4)
		capacity = capacity / 2;
	delete tryDeletePtr;
}

template<typename T>
int Heap<T>::findNode(T value){
	if(size == 0){
		std::cout<<"list is empty"<<std::endl;
		return -1;
	}
	Node<T>* tmpPtr = head;
	int i;
	for (i = 0;i < size; i++){
		if(tmpPtr->member == value){
			break;
		}
		tmpPtr = tmpPtr -> next;
	}
	if(i==size){
		std::cout<<"list do not have this value"<<std::endl;
		return -1;
	}
	return i;

}

template<typename T>
void Heap<T>::clear(){
	Node<T>* tmpPtr = head;
	Node<T>* deletePtr;

	for(int i=0;i<size;i++){
		deletePtr = tmpPtr;
		tmpPtr = tmpPtr -> next;
		delete deletePtr;
	}
	size = 0;
	capacity = 10;
}


template<typename T>
void Heap<T>::sortNode(){
}





#endif
