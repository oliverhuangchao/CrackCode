#include "3.h"
#include<iostream>
setOfStack::setOfStack():
	setSize(10),
	capacity(5),
	size(0),
	currentOrder(0),
	content(new int*[setSize]),
	top(new int[capacity]]),
	status(new int[setSize])
{
	*content = top;
}


void setOfStack::push(int value){
	if(size == capacity){
		if(currentOrder == setSize){
			std::cout<<"full stacks"<<std::endl;
			return ;
		}
		else{
			size = 1;
			top = new int[capacity];
			content[++currentOrder] = top;
			*top = value;
		}
	}
	else{
		*(++top) = value;
		size++;
	}
	*(status+currentOrder) = size;
}

int setOfStack::pop(){
	int value = *(top);
	size--;
	if(size == 0){
		delete top;
		top = content[--currentOrder];
	}
	*(status+currentOrder) = size;
	return value;
}

int setOfStack::popAt(int index){
	if(currentOrder == index){
		return pop();
	}
	else{
		int value =*(content[currentOrder] + capacity -1);
		return value;
	}
	*(status+index) = size;

}
