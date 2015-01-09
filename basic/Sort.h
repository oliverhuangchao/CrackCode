#include <iostream>
#include <cstring>
//------ declaration goes here ------
template<typename T>
T* mergeSort(T*,int,int);

template<typename T>
T* merge(T*,T*,int,int);

int choosePivot(int);

template<typename T>
int partition(T* Array,int,int);

template<typename T>
void quickSort(T*,int,int);

template<typename T>
void swapContent(T*,int,int);



//------ defination goes here ---=--
// swap two content in a vector
// given two label of the string
template<typename T>
void swapContent(T* input,int lhsLabel,int rhsLabel){
	T tmpPtr;
	tmpPtr = *(input + lhsLabel);
	*(input + lhsLabel) = *(input + rhsLabel);
	*(input + rhsLabel) = tmpPtr;
}



// merge two array together
template <typename T>
T* merge(T* x, T* y,int m,int n){
	int i,j,k;
	k = 0;
	i = j = 0;
	T* z = new T[m+n];
	while(1){
		if(i == m && j == n)
			break;

		if(i == m && j != n){
			*(z+k) = *(y+j);
			j++;
			k++;
			continue;
		}

		if(i != m && j == n){
			*(z+k) = *(x+i);
			i++;
			k++;
			continue;
		}

		if(*(x+i) >= *(y+j)){
			*(z+k) = *(x+i);
			i++;
		}else{
			*(z+k) = *(y+j);
			j++;
		}
		k++;
	}
	return z;
}
// --- recursive way to achieve merge sort ---
// merge sort main function
template<typename T>
T* mergeSort(T* input,int start, int end){
	int mid = (end - start)/2 + start;
	if(end > start){
		T* x = mergeSort(input,start,mid);
		T* y = mergeSort(input,mid+1,end);
		return merge(x,y,mid-start+1,end-mid);
	}
	return input+end;
}


//------ main function of quick sort ------
//input is array, start position and end position
template<typename T>
void quickSort(T* input,int start, int end){
	int m = partition(input,start,end);
	if(end<=start)
		return;
	if(start < m-1)
		quickSort(input,start,m-1);
	if(m+1 < end)
		quickSort(input,m+1,end);
}


//------ partition the content in the array ------
// size: should be one smaller than the actual size
template<typename T>
int partition(T* Array, int start, int end){
	int pivot = choosePivot(end-start);
	T pivotContent = *(Array+pivot+start);
	// swap the pivot to the endo of the array
	swapContent(Array, pivot+start, end);
	int p = end;
	// find out the first position whose content is bigger than pivot Content
	for(int i = start; i < end; i++){
		if(*(Array+i) > pivotContent){
			p = i;
			break;
		}
	}
	// from this first position to the end of the array
	for(int i=p+1;i<end;i++){
		if(*(Array+i) > pivotContent)
			continue;
		else{
			swapContent(Array,i,p);
			p++;
		}
	}
	swapContent(Array,end,p);
	// should return p
	return p;
}

