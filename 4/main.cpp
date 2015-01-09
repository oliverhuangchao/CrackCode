#include <iostream>
#include "6.h"
//using namespace std;


int main(){
	int x[] = {5,3,1,2,4,7,0};
	int l = sizeof(x)/sizeof(x[0]);
	std::stack<int> ori;
	for(int i=0;i<l;i++){
		ori.push(x[i]);
	}
	std::stack<int> ret;
	ret = insertSort(ori);
	print(ret);
}
