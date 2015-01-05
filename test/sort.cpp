#include <iostream>
#include <cstring>
#include <malloc.h>
using std::cout;using std::endl;

int* mergeSort(int*,int,int);
int* merge(int*,int*,int,int);
/*
------
merge two sorted array using ASCII order
-----
*/
/*
int* merge(int* x, int start, int mid, int end){
	int i,j,k;
	i = start;
	j = mid;
	k = 0;
	int* z = new int[end-start];
	while(1){
		if(i == mid && j == end)
			break;

		if(i == mid && j != end){
			*(z+k) = *(x+j);
			j++;
			k++;
			continue;
		}

		if(i != mid && j == end){
			*(z+k) = *(x+i);
			i++;
			k++;
			continue;
		}

		if(*(x+i) >= *(x+j)){
			*(z+k) = *(x+i);
			i++;
		}else{
			*(z+k) = *(x+j);
			j++;
		}
		k++;
	}
	return z;
}
*/
// merge two array together
int* merge(int* x, int* y,int m,int n){
	int i,j,k;
	k = 0;
	i = j = 0;
	int* z = new int[m+n];
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
int* mergeSort(int* input,int start, int end){
	int mid = (end - start)/2 + start;
	if(end > start){
		int* x = mergeSort(input,start,mid);
		int* y = mergeSort(input,mid+1,end);
		return merge(x,y,mid-start+1,end-mid);
	}
	return input+end;
}

std::ostream& operator<<(std::ostream& out, const int* data){
	return out<<*(data)<<'\n';
}

int main(){
	int x[] ={1,10,5,7,2,4};
	int l = sizeof(x)/sizeof(x[0])-1;
//	int y[] ={6,5,2};
	int* z;
	z = mergeSort(x,0,l);

//	z = merge(x,y,3,3);
	for(int i=0;i<l+1;i++)
		std::cout<<*(z+i)<<std::endl;
}
