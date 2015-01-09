#include "Sort.h"


int choosePivot(int x){
	if(x == 0)
		return x;
	else
		return rand() % x;
}


