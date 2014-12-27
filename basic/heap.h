#ifndef __myHeap__
#define __myHeap__

#include "linklist.h" 

template <typename T>
class myHeap{
public:
// memeber variables
	int heapSize;
	linklist<T> data;


// member functions
	myHeap();
	~myHeap();

	void insertData(T x);
	void clear();
	void deleteData();
	void retrive();//using heap attribute to print 
};



// defination of member functions
template<typename T>
myHeap<T>::myHeap():
	heapSize(0),
	data(linklist<T>())
{}

template<typename T>
myHeap<T>::~myHeap(){
// use linlist destruction function
}


template<typename T>
void myHeap<T>::insertData(T x){
	Node<T> newNode = new Node<T>(x);
	data->insertNode(newNode);
}




#endif
