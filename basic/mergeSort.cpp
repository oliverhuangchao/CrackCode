#include <iostream>
#include <cstring>
using std::cout;using std::endl;
/* 
------
merge two sorted array using ASCII order
-----
*/
char* merge(char* x, char* y){
	int i,j,k;
	i=j=k=0;
	char* z = new char [strlen(x) + strlen(y) + 1];
	while(1){
		if( strlen(z) == strlen(x) + strlen(y) )
			break;
		if( *(x+i) >= *(y+j) ){
			*(z+k) = *(x+i);
			i++;
		}else{
			*(z+k) = *(y+j);
			j++;
		}
		k++;
		//cout<<"k = "<<k<<'\t'<<"z = "<<z<<endl;
	}
	return z;
}

void mergeSort(char * input){
	char tmp_x = new char[strlen(input)+1];
	char tmp_y = new char[strlen(input)+1];
	merge(merge(tmp_x),merge(tmp_y));
}

int main(){
	char x[] ="zxb";
	char y[] ="ya";
	char* z;
	z = merge(x,y);
	std::cout<<z<<std::endl;
}
