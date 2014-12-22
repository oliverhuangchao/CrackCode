#ifndef NODE__H
#define NODE__H

template<typename T>
class Node{
public:
	T member;
	Node<T>* next;

// member functions
	Node<T>();
	Node<T>(const Node<T>& x);
	Node<T>(const T x);
};




#endif
