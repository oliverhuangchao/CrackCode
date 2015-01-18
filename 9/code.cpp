
#include "code.h"
// overload two functions for switch two figure
void Swap(int* x, int* y, int pos1, int pos2){
	int tmp = *(x+pos1);
	*(x+pos1) = *(y+pos2);
	*(y+pos2) = tmp;
}

void Swap(int* x, int pos1, int pos2){
	int tmp = *(x+pos1);
	*(x+pos1) = *(x+pos2);
	*(x+pos2) = tmp;
}

//------ 9.1 ------
//merge two arrays together
int* mergeTwoArray(int* x, int* y){
	//int *p = x;
	//int *q = y;
	int i = 0;
	int j = 0;
	while((x+i) != nullptr){
		if(*(x+i) <*(y+j)){
			i++;
		}
		else{
			Swap(x,y,i,j);
			i++;
			if(*(y+j) > *(y+j+1))
				Swap(y,j,j+1);
		}
	}
}

//------ 9.2 ------
//just put all tha anagram strings together


//------ 9.3 ------
//given a sorted array of n integers that has been rotated an unknown number of times, give an O(log n) algorithm that finds an element in the array. You may assume that the array was originally sorted in increasing order.
// first step get the rotate position r
// this procedure cost O(logn) time
int findRotatePos(int *x,int size){
	int start,end;
	start = 0;
	end = size-1;
	int mid = (end+start)/2;
	while(end - start > 0){
		if(x[mid] > x[start]){
			start = mid;
			mid = (end+start)/2;
		}
		else{
			end = mid;
			mid = (end+start)/2;
		}
	}
	return mid+1;
}
// second step
// find value in a sorted array
int findSortedPos(int* x,int size,int value){
	int start = 0;
	int end = size-1;
	int mid = (start+end)/2;
	while(end - start > 1){
		if(x[mid] == value)
			return mid;
		if(x[mid]<value){
			start = mid;
			mid = (start+end)/2;
		}
		else{
			end = mid;
			mid = (start+end)/2;
		}
	}
	return mid+1;
}


// third  step:  
// finish this position
int findPos(int* x,int size,int value){
	int result;
	int rpos = findRotatePos(x,size);
	if(value == x[size-1]) 
		return size-1;
	if(value > x[size-1]){ 
		result = findSortedPos(x,rpos,value);
	}
	else{
		int *p = x+rpos;
		result = findSortedPos(p,size-rpos,value)+rpos;
	}
	return result;
}

