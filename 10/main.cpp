#include "code.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>


int main(int argc, char** argv){
	clock_t a1 = clock();
	int m,n;
	if(argc>1)
		m = atoi(argv[1]);
	if(argc>2)
		n = atoi(argv[2]);
//------ main part ------

	std::cout<<fac(m)<<std::endl;
	std::cout<<permutation(m,n)<<std::endl;
	std::cout<<combination(m,n)<<std::endl;

//------ finish main part ------
	clock_t a2 = clock();
	std::cout<<"cost time isi "<<(double)(a2-a1)/CLOCKS_PER_SEC<<" s"<<std::endl;

}
