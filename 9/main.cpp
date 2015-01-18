#include "code.h"
#include <cstring>
#include <time.h>


int main(int arc, char** argv){
	clock_t a1 = clock();
	int n = atoi(argv[1]);


	clock_t a2 = clock();
	std::cout<<"cost time isi "<<(double)(a2-a1)/CLOCKS_PER_SEC<<" s"<<std::endl;

}
