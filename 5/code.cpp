#include "code.h"
#include <cmath>
#include <cstring>

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

// get the length of figure for its binary reprentation
int getBinaryLength(int x){
	int m,n;
	x = (unsigned int)x;
	for(int i = 0;i<32;i++){
		m = x & 1;
		if(m == 1) {
			n = i;
		}
		x = x>>1;
	}
	return n+1;
}

void switchFigure(int *x, int m, int n){
	int tmp = *(x+m);
	*(x+m) = *(x+n);
	*(x+n) = tmp;
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
//transfer a string to a decimal
double string2dec(char* x){
	int size = 0;// total size
	int front = 0;// integer part of this decimal
	while(*(x+size) != '\0'){
		if(*(x+size)=='.') front = size-1;
		size++;
	}
	double result = 0;
	char tmp;
	int i = 0;
	bool s=false;
	while(i<size){
		tmp = *(x+i);
		if(tmp == '.') {
			i++;s=true;continue;
		}
		if(!s)
			result += ((double)tmp - 48) * pow(10,(front-i));
		else
			result += ((double)tmp - 48) * pow(10,(front-i+1));
		i++;
	}
	return result;
}






//------ topic 5.3 ------





//------ topic 5.4 ------
//think twice and give the result
//if x is even, the result is x-1;
//if x is odd, the result is
//
//------ topic 5.5 ------

int countTransfer(int a,int b){
	int x = a^b;
	return  countOne(x);
}
// return how many ones in a integer
int countOne(int x){
	int count = 0;
	for(int i=0;i<32;i++){
		if((x&1) == 1)
			count++;
		x = x>>1;
	}
	return count;
}


//------ topic 5.6 ------
//switch odd and even bit of a integer
int switchOddandEven(int x){
	int size = getBinaryLength(x);
	size = (size%2)?size+1:size;
	int r,l;
	r=0;
	l=0;
	for(int i=0;i<size;i++){
		if(i%2==0)
			r += pow(2,i);
		else
			l += pow(2,i);
	}
	int m = x>>1 & r;
	int n = x<<1 & l;
	return m+n;
}

//------ topic 5.7 ------
//suppose x has no order
int returnMissing(int* x,int size){
	int c = ceil(log(size)+1);//how many bits maxiam;
	int result = 0;
	int i;
	int start = 0;
	int end = size;
	int last;
	int pivot=0;
	for(int j=0;j<c;j++){
		int m = size/pow(2,j);
		i = start;
		last = end;
		while(i<k){
			if(fetch(i,j) == 1){
				switchFigure(i,last);
				last--;
			}
			else{
				i++;
				pivot++;
			}
			if(i==(end-start)/2){
				result += pow(2,j);
				start = pivot+1;
			}
			else{
				end = pivot;
			}
			i = start;
			last = end
		}
	}
	return result;
}



