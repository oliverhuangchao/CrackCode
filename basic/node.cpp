#include "node.h"

template <typename T>
Node<T>::Node():
	member(),
	next(nullptr)
{}

template <typename T>
Node<T>::Node(const Node<T>& x):
	member(x.member),
	next(x.next)
{}

template <typename T>
Node<T>::Node(const T val):
	member(val),
	next(nullptr)
{}
