#include<iostream>
#include<cmath>
#include<string>
int main(){
	std::string x="hello";
	std::string::iterator p = x.begin();
	x = x.insert(2,1,'h');
	std::cout<<x<<std::endl;
}

