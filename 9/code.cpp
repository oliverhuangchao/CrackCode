#include <iostream>
#include <vector>
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
	while(*(x+i) != null){
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
