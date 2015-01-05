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

	bool deleteNode(T);
	void mergeTree(Node<T>*, Node<T>*);
	void clear();
	void inorderTraversal(Node<T>*);
	Node<T>* findMin(Node<T>*);// input is the starting root node
	Node<T>* findMax(Node<T>*);// input is the starting root node
	Node<T>* predecessor(T);
	Node<T>* successor(T);
	int getHeight(Node<T>*);//get the height of the tree recursively
};

//overload << operator
template<typename T>
std::ostream& operator<<(std::ostream& out, const Node<T>* node){
	if(node == nullptr)
		return out<<"null"<<'\n';
	else
		return	out<<node->member<<'\n';
}

//get the height of the tree recursively
template<typename T>
int BST<T>::getHeight(Node<T>* node){
	if(node != nullptr){
		int l = getHeight(node->left);
		int r = getHeight(node->right);
		return (l>r?l:r)+1;
	}
	else{
		return 0;
	}
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
//		std::cout<<"inorderTraversl: list is empty"<<std::endl;
		return;
	}
	else{
		inorderTraversal(node->left);
		std::cout<<node->member<<std::endl;;
		inorderTraversal(node->right);
	}
}

//------ find the min of the bst ------
template<typename T>
Node<T>* BST<T>::findMin(Node<T>* node){
	Node<T>* tmpPtr = node;
	while(tmpPtr->left != nullptr){
		tmpPtr = tmpPtr->left;
	}
	return tmpPtr;

}



//------ find the max of the bst ------
template<typename T>
Node<T>* BST<T>::findMax(Node<T>* node){
	Node<T>* tmpPtr = node;
	while(tmpPtr->right != nullptr){
		tmpPtr = tmpPtr->right;
	}
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
					newNode->parent = tmpPtr;
					break;
				}
				else
					tmpPtr = tmpPtr->right;
			}
			else{
				if(tmpPtr->left == nullptr){
					tmpPtr->left = newNode;
					newNode->parent = tmpPtr;
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
bool BST<T>::deleteNode(T value){
	if(size == 0){
		std::cout<<"bst is empty"<<std::endl;
		return false;
	}
	Node<T>* node = findNode(value);
	if(node == nullptr){
		std::cout<<"this value does not exist"<<std::endl;
		return false;
	}
	//case I: node has no child
	if(node->left == nullptr && node->right == nullptr){
		if(node->member < node->parent->member)
			node->parent->left = nullptr;
		else
			node->parent->right= nullptr;
		delete node;
		size--;
		return true;
	}
	//case II: node has one child
	if(node->left == nullptr xor node->right == nullptr){
		if(node->member > node->parent->member){
			if(node->right != nullptr)
				node->parent->right = node->right;
			else
				node->parent->right = node->left;
		}
		else{
			if(node->right != nullptr){
				node->parent->left= node->right;
				node->right->parent = node->parent;
			}
			else{
				node->parent->left = node->left;
				node->left->parent = node->parent;
			}
		}
		delete node;
		size--;
		return true;
	}
	//case III: node has two children
	if(node->left != nullptr && node->right != nullptr){
		Node<T>* tmp = successor(node->member);
		Node<T>* suc= new Node<T>(tmp->member);
		deleteNode(tmp->member);

		if(node->left != nullptr){
			node->left->parent = suc;
			suc->left = node->left;

		}

		if(node->right!= nullptr){
			node->right->parent = suc;
			suc->right = node->right;
		}

		suc->parent = node->parent;
		if(node == root) root = suc;

		delete node;
		size--;
		return true;
	}
}


//------ search a node in iteration way ------
template<typename T>
Node<T>* BST<T>::findNode(T value){
	if(size == 0){
		std::cout<<"findNode: list is empty"<<std::endl;
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

// ------ search a node in recursive way ------
template<typename T>
Node<T>* BST<T>::findNode(T value, Node<T>* node){
	Node<T>* tmpPtr;
	if(node->member == value)
		return node;
	if(node->left ==  nullptr && node->right == nullptr)
		return nullptr;
	if(node-> member > value){
	  	tmpPtr = findNode(value,node->left);
	}
	else{
		tmpPtr = findNode(value,node->right);
	}
	return tmpPtr;
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

//------ find the predecessor in ths list ------
template<typename T>
Node<T>* BST<T>::predecessor(T value){
	Node<T>* tmpPtr= findNode(value);
	if(tmpPtr->left== nullptr){
		//Node<T>* tmpPtr = node->parent;
		while(1){
			if(tmpPtr->parent->right == tmpPtr)
				return tmpPtr->parent;
			else
				tmpPtr = tmpPtr->parent;
			if(tmpPtr->parent == nullptr){
				//std::cout<<"null"<<std::endl;
				return nullptr;
				break;
			}
		}
	}
	else{
		return findMax(tmpPtr->left);
	}
}

//------ find the successor in ths list ------
template<typename T>
Node<T>* BST<T>::successor(T value){
	Node<T>* tmpPtr= findNode(value);
	if(tmpPtr->right == nullptr){
		//Node<T>* tmpPtr = node->parent;
		while(1){
			if(tmpPtr->parent->left == tmpPtr)
				return tmpPtr->parent;
			else
				tmpPtr = tmpPtr->parent;
			if(tmpPtr->parent == nullptr){
				//std::cout<<"null"<<std::endl;
				return nullptr;
				break;
			}
		}
	}
	else{
		return findMin(tmpPtr->right);
	}
}
#endif
