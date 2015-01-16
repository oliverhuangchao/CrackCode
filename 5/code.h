#include <string>
#include <iostream>
//------ basic operation -----
// exchange between decimal and binary
int dec2binary(int);
int binary2dec(int);
int getBinaryLength(int);// get the length of figure for its binary reprentation
//------5.1------
//set all bits between i and j in N equal to M
//
void mergeTwo(int m,int n, int i,int j);


//------ 5.2 ------
//transfer a string to a decimal
double string2dec(char*);


//------ 5.5 ------
//get the number of bit transfer from a to b

int countTransfer(int a,int b);
// return how many ones in a integer
int countOne(int);


//------ 5.6 ------
//switch odd and even bit of a fiture
int switchOddandEven(int);
