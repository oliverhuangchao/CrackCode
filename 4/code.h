#include "../basic/bst.h"

//4.2 given two nodes in a graph, check whether there is a route between them
//we can use DFS or BFS between them.
//BFS can find the shortest way
//DFS can find the leaf node in the first time


//4.3
// given a ordered array and build a tree with minimal height
// reorder this array and input the array into a bt
// attention: this is just a binary tree not a binary search tree
// difference: BST's left node should smaller than the root node, BT is not
//

// we can also directly build a binary search tree for that


//non recursive method is written in bst.h
//or you can use resursive method  also included in bst.h



//4.4
//Given a binary search tree, design an algorithm which creates a linked list of all the
//nodes at each depth (i.e., if you have a tree with depth D, you’ll have D linked lists)
// below is a general function


template<typename T>
std::list<Node<T>* > makelink(const std::list< Node<T> >& prelist){
	std::list<Node<T>* > prolist;
	for(int i=0;i<prelist.size();i++){
		if(prelist[i]->left!= nullptr)
			prolist.add(prelist[i]->left);
		if(prelist[i]->right!= nullptr)
			prolist.add(prelist[i]->right);
	}
	return prolist;
}


//------ main function for 4.4 -------
//use the function define above
template<typename T>
void getLists(BST<T>* bst){
	std::vector<Node<T>* > listVector;
	int height = bst->getHeight(bst->root);
	int count = 0;
	while(count < height){
		if(count == 0)
			listVector[count].add(bst->root);
		else{
			listVector[count]=makelink(listVector[count]);
		}
	}
}


//another way to solve this problem
//using BFS we can also solve this problem
//firstly, we need to get each value's height;
//when we tend to pop some value from the queue, we can have a check about the height, if the height changed we create a new list, else we just add the current node to the old list
//BFS function in bst.h



//------ 4.7 subtree problem ------
//a big tree T1 millons of nodes and T2 is a small tree with hundreds of nodes.
// decide whether T2 is the subtree of T1
// my solution is not equal to the answer in crackcode
// my solution is:
// firstly, find the root of bst2 in bst1
// secondly, tranversal each node in bst2
template<typename T>
bool isSubtree(BST<T>* bst1, BST<T>* bst2){
	Node<T>* node = bst1->find(bst2->root->member);
	if(node == nullptr){
		std::cout<<"T2 is not a subtree of T1"<<std::endl;
		return false;
	}
	else{
		bst1->BFS(node);
		bst2->BFS(bst2->root);
	}
}







//------ 4.6 how to find the first common ansestor between two nodes in a tree ------
//input two values
//use a new function named bst::getRoute(node), return a list for a given node
template<typename T>
Node<T>* firstCommon(BST<T>* bst1, Node<T>* n1, Node<T>* n2){
	std::list<Node<T>*> list1,list2;
	list1 = bst1->getRoute(n1);
	list2 = bst1->getRoute(n2);
	Node<T>* tmpNode = nullptr;
	while(1){
		if(!list1.empty() && !list2.empty()){
			if(list1.front()->member == list2.front()->member){
				tmpNode = list1.front();
				list1.pop_front();
				list2.pop_front();
				continue;
			}
		}
		else{
			return tmpNode;
		}
	}
}


