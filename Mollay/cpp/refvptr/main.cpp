#include <iostream>

int main() {
  int x = 99;
  int y = 8;
  int* ptrToX = &x;
  int& refToX = x;
  std::cout << "x is: " << *ptrToX << std::endl;
  std::cout << "x is: " << refToX << std::endl;
  refToX = 17;
  std::cout << "x is: " << *ptrToX << std::endl;
  x = 50;
  std::cout << "x is: " << *ptrToX << std::endl;
  *ptrToX = 13;
  std::cout << "x is: " << refToX << std::endl;
  refToX = y;
  std::cout << "x is: " << *ptrToX << std::endl;
}
