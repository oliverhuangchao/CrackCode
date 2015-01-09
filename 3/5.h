/*
 *implement a queue with two stacks
 * think carefully about how to make these two stacks work together well
 * */
#define __MYQUEUE__
#ifdef __MYQUEUE__
//include "../basic/stack.h"
#include <stack>
class MyQueue{
public:
	std::stack<int> s1,s2;
	int size;
	int capacity;

	MyQueue();
	int out();
	bool in(int value);
	bool isEmpty();
	bool print();
};
#endif
