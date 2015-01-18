#include "code.h"
#include <cstring>
#include <stdlib.h>
#include <time.h>


int main(int arc, char** argv){
	clock_t a1 = clock();
	int n = atoi(argv[1]);
//------ main part ------
	int x[]={6,7,8,0,1,2,3,4,5};
	int l = sizeof(x)/sizeof(x[0]);
	int z = findPos(x,l,n);
	std::cout<<"size is "<<l<<std::endl;
	std::cout<<"rotate position for "<<n<<" is "<<z<<std::endl;

//------ finish main part ------
	clock_t a2 = clock();
	std::cout<<"cost time isi "<<(double)(a2-a1)/CLOCKS_PER_SEC<<" s"<<std::endl;

}
