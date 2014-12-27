#ifndef NODE__H
#define NODE__H
#include <iostream>
template<class T>
class Node{
public:
	T member;
	Node<T>* next;

	Node();
	Node(const Node& x);
	Node(const T x);
};

//----- defination goes here -----
template <class T>
Node<T>::Node():
	member(),
	next(nullptr)
{}

template <class T>
Node<T>::Node(const Node& x):
	member(x.member),
	next(x.next)
{}

template <class T>
Node<T>::Node(const T val):
	member(val),
	next(nullptr)
{}


#endif
