/*
4.2 given two nodes in a graph, check whether there is a route between them
we can use DFS or BFS between them.
BFS can find the shortest way
DFS can find the leaf node in the first time
*/
/* 
4.3
// given a ordered array and build a tree with minimal height
// reorder this array and input the array into a bt
// attention: this is just a binary tree not a binary search tree
// difference: BST's left node should smaller than the root node, BT is not
//

// we can also directly build a binary search tree for that


//non recursive method is written in bst.h
//or you can use resursive method  also included in bst.h
*/

/*
4.4
Given a binary search tree, design an algorithm which creates a linked list of all the
nodes at each depth (i.e., if you have a tree with depth D, you’ll have D linked lists)
// below is a general function
*/

template<typename T>
std::list<Node <T>> makelink(const std::list< Node<T> >& prelist){
	std::list<Node<T>> prolist;
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
template<Typename T>
void getLists(const BST<T>* bst){
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
