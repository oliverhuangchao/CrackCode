#include "code.h"
//------ create fibonacci sqeuence ------
int getFib(int* x,int n){
	//if(*(x+n) !=0) return *(x+n);
	if(n<=1){
		*(x+n) = 1;
		return 1;
	}
	else{
		*(x+n) = (getFib(x,n-1)+getFib(x,n-2));
		return *(x+n);
	}
}


//------ 8.2 ------
//------ move of a robot -------
//a robot start from left-top of a matrix NxN, how many ways does it have

int countWay(int i,int j){
	if(i==0 && j==0) return 1;
	else{
		if(i==0) return countWay(0,j-1);
		if(j==0) return countWay(i-1,0);
		return countWay(i-1,j)+countWay(i,j-1);
	}
}


//------ 8.3 ------
//return all subsets of a set

void getSubset(int* x,int size){

}

//------ 8.4 ------
//return all the permutation of a string
//
std::vector<std::string> getPermutation(const std::string& x,int n){
	std::vector<std::string> z;
	std::vector<std::string> y;
	std::string tmp;
	std::string ori = x.substr(0,n);
	if(ori.size() == 1){
		z.push_back(ori);
		return z;
	}
	else{
		y = getPermutation(x,n-1);
		std::string y_copy;
		for(int i=0;i<y.size();i++){
			y_copy = y[i];
			for (int k=0;k<n;k++){
				tmp = y[i].insert(k,1,x[n-1]);// insert will change the content of y, so next step will also be changed
				z.push_back(tmp);
				y[i] = y_copy;
			}
		}
		return z;
	}
}


//------ 8.5 ------//
//print all combination of parentheses

std::vector<std:string> getParentheses(){
}
