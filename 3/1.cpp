/* CrackCode interview charter 3-1
// implement 3 stacks with one array
// suppose each stack has same size
// suppose default type is integer
*/
#include <iostream>
// globel variable
int gorder = 0;// how many globle array 
int gsize = 0;// what is the globle size 
class stack{
public:
	int order;
	int* top;
	int capacity;
	int size;

	stack(int*,int);
	~stack();
	void push(int);
	int pop();
	bool isEmpty();
	bool isFull();
	void clear();
};

stack::stack(int* array,int size):
top(array+gsize),
order(gorder),
capacity(size),
size(0)
{
	gorder++;
	gsize+=size;
}

void stack::push(int value){
	if(isFull()){
		std::cout<<"stack is full"<<std::endl;
		return;
	}
	top++;
	*top = value;
}

int stack::pop(){
	if(isEmpty()){
		std::cout<<"stack is empty"<<std::endl;
		return 0;
	}
	int value = *(top);
	*top = 0;
	top --;
	return value;
}

bool stack::isEmpty(){
	return (*top == 0)? true: false;
}

bool stack::isFull(){
	return (size == capacity)? true: false;

}
void stack::clear(){
	for (int i = size;i>=0;i-- ){
		*(top) = 0;
		top --;
	}
	return ;
}

