#ifndef __myHeap__
#define __myHeap__

#include <iostream>
#include <list>

template <typename val>
class myHeap{
public:
// memeber variables
	int heapSize;
	std::list<val> data;
// member functions
	void insert(val x);
	void delete();
};

#endif
