#include "code.h"
#include <cstring>
#include <time.h>


int main(int arc, char** argv){
	clock_t a1 = clock();
	int n = atoi(argv[1]);
//------- 8.1 main function ------
/*

	int *x = new int[n];
	int z = getFib(x,n);
	for(int i=0;i<n;i++)
		std::cout<<*(x+i)<<std::endl;
*/

//------- 8.2 main function ------
//std::cout<<countWay(n,n)<<std::endl;

//------- 8.4 main function ------
	std::cout<<strlen(argv[1])<<std::endl;
	std::vector<std::string> result = getPermutation(argv[1],strlen(argv[1]));
	for(int i = 0;i<result.size();i++){
		std::cout<<result[i]<<std::endl;
}

	clock_t a2 = clock();
	std::cout<<"cost time isi "<<(double)(a2-a1)/CLOCKS_PER_SEC<<" s"<<std::endl;

}
