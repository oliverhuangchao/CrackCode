/*----
all the topic in CrackCode Interview will be listed here
*/

#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>
#include <tr1/functional>// hash function
#include "DT.h"

using std::cout; using std::endl;


/*----
 * 1.1
 * determine if a string has all unique characters 1.1
----*/

bool find_UniqueString(const std::string& text)
{
	std::tr1::hash <char> hashfunc;
	std::map <char, int> hashmap;
	std::map <char, int> ::const_iterator hashmap_Ptr;
	for (int i = 0; i< text.size(); i++)
	{
		hashmap_Ptr = hashmap.find(text[i]);
		if(hashmap_Ptr != hashmap.end())
			return false;
		else
			hashmap[text[i]] = hashfunc(text[i]);
	}
	return true;
}

/*-----
 * 1.2
 *	string invert function 1.2 using string class
 * ------*/
std::string reverseString(const std::string &inputString)
{
	std::string newString;
	if (inputString.empty()){
		return inputString;
	}
	std::string::const_iterator ptr = inputString.end();
	while(ptr != inputString.begin())
	{
		newString.push_back( *ptr );
		ptr --;
	}
	newString.push_back( *ptr );
	//std::cout<<newString.size()<
	return newString;
}
/* using c style string */

char* reverseCString(char *x)
{
	if (x == NULL)
		return x;
	int len = strlen(x);
	if (len < 2)
		return x;

	return x;
}
/*---
 * 1.3
 * remove the duplicate characters in a given string 1.3
 *	ps: no extra space can be created
 * -----*/
void removeDuplicate(std::string& inputString)
{
	std::string::iterator ptr = inputString.begin();
	for (ptr; ptr <= inputString.end(); ptr++){
		cout<<inputString.rfind(*ptr) <<'\t'<< inputString.find(*ptr)<<endl;
		if(inputString.rfind(*ptr) != inputString.find(*ptr) ){
			inputString.erase(ptr);
		}
	}
	return;
}


/*
 *1.8
 *test whether a string is a rotation of another string
 *
 */
//bool isRotation()
