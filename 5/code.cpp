#include "code.h"
#include <cmath>

int dec2binary(int x){
	int z = 0;
	int count = 0;
	while(x>0){
		z += (x % 2) * pow(10,count++);
		x /= 2;
	}
	return z;
}

int binary2dec(int x){
	int z = 0;
	int count = 0;
	while(x>0){
		z += (x % 10)*pow(2,count++);
		x /= 10;
	}
	return z;
}


//------ topic 5.1 ------
void mergeTwo(int n,int m, int i,int j){
	m = m << i;
	n = n >> j;
	n = n << j;
	n = n | m;
	std::cout<<dec2binary(n)<<std::endl;
}
//------ topic 5.2 ------
//------ topic 5.3 ------
//------ topic 5.4 ------
//think twice and give the result
//if x is even, the result is x-1;
//if x is odd, the result is
//
//------ topic 5.5 ------
//------ topic 5.6 ------
//
//
