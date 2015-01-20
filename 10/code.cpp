#include "code.h"
#define max(a,b)(a>b?a:b)
#define min(a,b)(a>b?b:a)


//------ get the lowest common multiple ------
int LCM(int x,int y){
	return (x*y)/GCD(x,y);
}


//------- get the greatest common divisor ------
//recursively achieve this goal
int GCD(int x,int y){
	int a,b;
	a = max(x,y);
	b = min(x,y);
	if( a/b*b == a)
		return b;
	else
		return GCD(b,a-a/b*b);
}

//------ get the factorial result ------
// x!
int fac(int x){
	// recursive way
	//	return x*fac(x-1);


	// not recursive way
	int z = 1;
	while(x>0){
		z *= x;
		x--;
	}
	return z;
}

//------- permutation -----
nt permutation(int x,int y){
	return fac(x)/fac(x-y);
}


//------ combination ------
int combination(int x,int y) {
	return permutation(x,y)/permutation(y,y);
}


//------ multiply opertation with only add -------
int mul(int x,int y){
	int z = 0 ;
	for(int i=0;i<y;i++){
		z += x;
	}
	return z;
}

//------ divide operation with only add -------
double div(int x,int y,int acc){
	int count = 0;
	while(x-y>0){
		x-= y;
		count++;
	}
	for(int i=0;i<acc<i++){
		if(x>0){
			count += div(mul(x,10),y);
		}
		else{
			return count;
		}
	}
}
