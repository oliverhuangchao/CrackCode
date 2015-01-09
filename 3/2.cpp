#include "2.h"

myStack::myStack():
size(0),
capacity(100),
top(new int[capacity]),
min(new int[capacity])
{}

void myStack::push(int value){
	if(isFull()){return;}
	top++;
	*(top) = value;
	if(size == 0)
		*min = value;
	else{
		if(value < *min)
			*(++min) = value;
		else{
			int tmp = *(min);
			*(++min) = tmp;
		}
	}
	size++;
}

int myStack::pop(){
	if(isEmpty()){return -1;}
	int value = *(top);
	top--;
	min--;
	return value;
}

int myStack::findMin(){
	return *min;
}


bool myStack::isFull(){
	return (size == capacity)? true:false;
}

bool myStack::isEmpty(){
	return (size == 0)? true:false;
}