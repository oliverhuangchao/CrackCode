#define __SETOFSTACKS__
#ifdef __SETOFSTACKS__

class setOfStacks{
public:
	int setSize;
	int capacity;
	int size;// current size of each stack
	int currentOrder;//current Order of stacks
	int** content;
	int* top;
	int* status;// contains the current size of each sub-stack

	setOfStacks();
	void push(int);
	int pop();
	int popAt(int);
};


#endif
