#include <cstring>
#include <iostream>

using std::cout;using std::endl;

char* replaceWith20(char* x){
	if(x == NULL)
		return x;
	int len = strlen(x);
	for (int i = 0;i < len;i++)
	{
		if (*(x+i) == ' ')
			*(x+i) = '%';
	}
	return x;
}


int main(){
	char *x = "hello world";
	cout<<x<<endl;
	char *y = replaceWith20(x);
	cout<<y<<endl;
}
