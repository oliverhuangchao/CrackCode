//   The file student.h contains a class definition, and 
//   file student.cpp contains a class implementation.
//   This file contains the main function.

#include <iostream>
using std::cout; using std::endl;
#include "student.h"

int main() {
  Student bill(3.4);
  bill.display();
  return 0;
}
