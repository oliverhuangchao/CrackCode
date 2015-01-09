/*
CrackCode interview charter 3-2
design a myStack has the following three functions:
1. push
2. pop
3. min


method:
1. create another min_myStack same with value stack, but min_stack push all the min_stack currently in the value_stack
	in every push operation, just compare the comming integer with the value on the top of the min_myStack
	push the value: O(1)
	push the min:O(1) + O(1)
*/

#define __myStack__
#ifdef __myStack__

class myStack{
public:
	int size;
	int capacity;
	int* top;
	int* min;

	myStack();

	void push(int);
	int pop();
	int findMin();
	bool isEmpty();
	bool isFull();
};


#endif
