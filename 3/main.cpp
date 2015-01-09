#include<iostream>
#include"5.h"
//using namespace std;


int main(){
	int x[] = {1,3,5,6,7,2,3,4,5,0};
	int l = sizeof(x)/sizeof(x[0]);
	MyQueue myqueue;
	myqueue.in(x[1]);
	myqueue.in(x[2]);
	myqueue.out();
	myqueue.in(x[3]);
	myqueue.in(x[4]);
	myqueue.out();
	myqueue.in(x[5]);
	myqueue.print();
}
