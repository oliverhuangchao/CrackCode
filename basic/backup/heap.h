#ifndef __myHeap__
#define __myHeap__

#include "linklist.h"

template <typename T>
class myHeap{
public:
	int heapSize;
	linklist<T> data;

	myHeap();
	~myHeap();

	void insertData(T x);
	void clear();
	void deleteData();
	void retrive();//using heap attribute to print
	void reorder();//make the heap in the right order
};



// defination of member functions
template<typename T>
myHeap<T>::myHeap():
	heapSize(0),
	data(linklist<T>())
{
	std::cout<<"construct a heap!!!"<<std::endl;
}

template<typename T>
myHeap<T>::~myHeap(){
// use linlist destruction functionp
	std::cout<<"destruct a heap!!!"<<std::endl;
	heapSize = 0;
}


template<typename T>
void myHeap<T>::insertData(T x){
	Node<T> newNode = new Node<T>(x);
	data->insertNode(newNode);//insert at the end of the list
	reorder();
}

template<typaname T>
void myHeap<T>::reorder(){
	std::cout<<"reorder the heap!!"<<std::endl;
}


#endif
