#include<iostream>

int main(){
	int* a = new int[10];
	int* b = new int[10];
	int* c = new int[10];
	*a = 1;
	*c = 222;
	b = a;
	a = c;
	std::cout<<*(a)<<'\t'<<*b<<'\t'<<*c<<std::endl;
}
