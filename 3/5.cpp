#include "5.h"
#include <iostream>

MyQueue::MyQueue():
	s1(),
	s2(),
	size(0),
	capacity(100)
{}

bool MyQueue::in(int value){
	if(size != capacity){
		s1.push(value);
		size++;
		return true;
	}
	else{
		std::cout<<"queue is full"<<std::endl;
		return false;
	}
}

int MyQueue::out(){
	if(!s2.empty()){
		int value = s2.top();
		s2.pop();
		size--;
		return value;
	}
	else{
		if(!s1.empty()){
			int tmp = s1.size();
			int value;
			for(int i = 0;i<tmp;i++){
				s2.push(s1.top());
				s1.pop();
			}
			value = s2.top();
			s2.pop();
			size--;
			return value;
		}
		else{
			std::cout<<"empty queue"<<std::endl;
			size--;
			return -1;
		}
	}
}

bool MyQueue::isEmpty(){
	if(s1.empty() && s2.empty())
		return true;
	else
		return false;
}

bool MyQueue::print(){
	if(isEmpty()){
		std::cout<<"empty queue"<<std::endl;
		return false;
	}
	while(!isEmpty()){
		std::cout<<out()<<std::endl;
	}
	return true;
}
