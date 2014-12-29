#include <cstdlib>
#include <iostream>

int main() {
  int x = 17;
  int y = 9;
  const int * const ptrToX = &x;
  std::cout << "x is: " << *ptrToX << std::endl;
}
