#include "6.h"
#include <iostream>
std::stack<int> insertSort(std::stack<int>& ori){
	std::stack<int> ret;
	int value;
	while(!ori.empty()){
		value = ori.top();
		ori.pop();
		while(!ret.empty() && ret.top() > value){
			ori.push(ret.top());
			ret.pop();
		}
		ret.push(value);
	}
	return ret;
}

void print(std::stack<int> ori){
	while(!ori.empty()){
		std::cout<<ori.top()<<std::endl;
		ori.pop();
	}
}
