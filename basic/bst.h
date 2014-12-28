#ifndef BST__H
#define BST__H

#include "node.h"

template <typename T>
class BST{
public:
	int size;
	int capacity;
	Node<T>* root;

	BST();
	~BST();

	void insertNode(T);
	Node<T>* findNode(T);
	Node<T>* findNode(T,Node<T>*);

	void deleteNode(int);
	void clear();
	void inorderTraversal(Node<T>*);
	Node<T>* findMin();
	Node<T>* findMax();
};

//overload << operator
template<typename T>
std::ostream& operator<<(std::ostream out, const Node<T>* node){
	out<<node->member<<'\n';
}


//------ bst construction function ------
template<typename T>
BST<T>::BST():
	size(0),
	capacity(10),
	root(nullptr)
{
	std::cout<<"default construct BST"<<std::endl;
}

template<typename T>
BST<T>::~BST(){
	clear();
	std::cout<<"distruct BST"<<std::endl;
}

//------ inorder traversal all the nodes in the list ------
// written in recursive method
template<typename T>
void BST<T>::inorderTraversal(Node<T>* node){
	if(node == nullptr){
		//std::cout<<"list is empty"<<std::endl;
		return;
	}
	else{
		//std::cout<<node->member<<std::endl;
		//Node<T>* tmpPtr = root;
		inorderTraversal(node->left);
		std::cout<<node->member<<std::endl;;
		inorderTraversal(node->right);
	}
//	std::cout<<std::endl;
}

//------ find the min of the bst ------
template<typename T>
Node<T>* BST<T>::findMin(){
	Node<T>* tmpPtr = root;
	while(tmpPtr->left != nullptr){
		tmpPtr = tmpPtr->left;
	}
	std::cout<<tmpPtr->member<<std::endl;
	return tmpPtr;

}



//------ find the max of the bst ------
template<typename T>
Node<T>* BST<T>::findMax(){
	Node<T>* tmpPtr = root;
	while(tmpPtr->right != nullptr){
		tmpPtr = tmpPtr->right;
	}
	std::cout<<tmpPtr->member<<std::endl;
	return tmpPtr;
}

//------ insert a new node into the structure ------
template<typename T>
void BST<T>::insertNode(const T val){
	Node<T>* newNode = new Node<T>(val);

	if(size == 0)
		root = newNode;
	else{
		Node<T>* tmpPtr = root;
		while(1){
			if(newNode->member > tmpPtr->member){
				if(tmpPtr->right == nullptr){
					tmpPtr->right = newNode;
					break;
				}
				else
					tmpPtr = tmpPtr->right;
			}
			else{
				if(tmpPtr->left == nullptr){
					tmpPtr->left = newNode;
					break;
				}
				else{
					tmpPtr = tmpPtr->left;
				}
			}
		}
	}
	size++;
}

/* delete node using order number
order: should begin from 0, keep same setting in main file
*/
template<typename T>
void BST<T>::deleteNode(int order){
	if(order > size || order <= 0) std::cout<<"out of list member"<<std::endl;
	Node<T>* tmpPtr = root;
	for (int i = 0;i < order - 1; i++){
		tmpPtr = tmpPtr -> next;
	}
	Node<T>* tryDeletePtr = tmpPtr->next;
	tmpPtr->next = tryDeletePtr->next;
	size--;
	if(size < capacity/4)
		capacity = capacity / 2;
	delete tryDeletePtr;
}


//------ search a node in the iteration way ------
template<typename T>
Node<T>* BST<T>::findNode(T value){
	if(size == 0){
		std::cout<<"list is empty"<<std::endl;
		return nullptr;
	}
	Node<T>* tmpPtr = root;
	int i;
	while(1){
		if(tmpPtr->member == value)
			return tmpPtr;
		if(tmpPtr->member > value){
			tmpPtr = tmpPtr->left;
		}
		else{
			tmpPtr = tmpPtr->right;
		}
		i++;
		if(i==size){
			std::cout<<"list do not have this value"<<std::endl;
			return nullptr;
		}
	}
}

// ------ search recursive way ------
template<typename T>
Node<T>* BST<T>::findNode(T value, Node<T>* node){
	if(node->member == value)
		return node;
	if(node->left ==  nullptr || node->right == nullptr)
		return nullptr;
	if(node-> member > value){
		findNode(value,node->left);
	}
	else{
		findNode(value,node->right);
	}
}

// ------ clear all the contents in the list ----
template<typename T>
void BST<T>::clear(){
	if(size != 0){
	Node<T>* tmpPtr = root;
	Node<T>* deletePtr;

	for(int i=0;i<size;i++){
		deletePtr = tmpPtr;
		tmpPtr = tmpPtr -> next;
		delete deletePtr;
	}
	size = 0;
	capacity = 1;
	}
}
#endif
