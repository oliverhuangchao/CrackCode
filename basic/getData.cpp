#include<cstring>
#include<iostream>
#include<fstream>


#include "getData.h"
//
//return data through a file 
//input: filename:file's name'
//input: Count:count of input you want 
//
std::string* ReturnData(const std::string filename,int Count){

	std::ifstream readfile;
	std::string line;
	std::string* resultData = new std::string[Count];
	readfile.open(filename.c_str(),std::ios::in);
	int num = 0;
	if(readfile.fail()){
		std::cout<<"this file does not exist"<<std::endl;
		return nullptr;
	}
	else{
		while(getline(readfile,line,'\n')){
			resultData[num++] = line;
			if(num == Count)
				break;
		}
		return resultData;
	}
}


// return how many lines totally a file have
// input:filename: file's name'
int ReturnCount(const std::string filename){
	std::ifstream readfile;
	readfile.open(filename.c_str(),std::ios::in);
	std::string tmpline;
	int count = 0;
	if(readfile.fail()){
		std::cout<<"cannot find this file"<<std::endl;
		return -1;
	}
	else{
		while(getline(readfile,tmpline,'\n')){
			count++;
		}
	}
	return count;
}


		
	
