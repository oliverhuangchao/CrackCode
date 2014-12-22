#include "linklist.h"
#include <iostream>
/*
template<typename T>
Linklist<T>::Linklist():
	size(0),
	capacity(10),
	head(nullptr),
	tail(nullptr)
{}
*/
template<typename T>
void Linklist<T>::print(){
	if(size == 0)
		std::cout<<"list is empty"<<std::endl;
	for(int i = 0;i<size;i++){
		std::cout<<head->member<<std::endl;
		head = head -> next;
	}
}


template<typename T>
void Linklist<T>::insertNode(const T val){
	Node<T>* newNode = new Node<T>(val);

	if(size == 0)
		head->next = newNode;
	else{
		Node<T>* tmpPtr = head;
		for(int j=0;j<size;j++)
			tmpPtr = tmpPtr->next;
		tmpPtr->next = newNode;
	}
	newNode->Next = tail;
	size++;
	if(size == capacity/2)
		capacity = capacity * 2;
}

template<typename T>
void Linklist<T>::deleteNode(int order){
	if(order > size || order <= 0) std::cout<<"out of list member"<<std::endl;
	Node<T>* tmp = head;
	for (int i = 0;i < order-1; i++){
		tmp = tmp -> next;
	}
	Node<T>* tryDeletePtr = tmp->next;
	tmp->next = tmp->next->next;
	size--;
	if(size < capacity/4)
		capacity = capacity / 2;
	delete tryDeletePtr;
}

template<typename T>
void Linklist<T>::deleteNode(T value,int order){
	order = 0;
	Node<T>* tmpPtr = head;
	int i;
	for (i = 0;i < size; i++){
		if(tmpPtr->memeber == value){
			Node<T>* deletePtr = tmpPtr;
			tmpPtr->next  = tmpPtr->next->next;
			delete deletePtr;
			size--;
			break;
		}
		tmpPtr = tmpPtr -> next;
	}
	if(i==size)
		std::cout<<"delete it"<<std::endl;
	else
		std::cout<<"do not find it"<<std::endl;
	if(size < capacity/4)
		capacity = capacity / 2;
}

template<typename T>
void Linklist<T>::clear(){
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
void Linklist<T>::sortNode(){
}


