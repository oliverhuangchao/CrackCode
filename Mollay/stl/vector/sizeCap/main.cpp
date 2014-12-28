#include <cstdlib>
#include <iostream>
#include <vector>

void printStats(const std::vector<int>& vec) {
  std::cout << "size: " << vec.size() << std::endl;
  std::cout << "cap: " << vec.capacity() << std::endl;
}

int main() {
  std::vector<int> vec;
  vec.reserve(1000000);
  for (unsigned int i = 0; i < 1000000; ++i) {
    vec.push_back(rand() % 100);
    //vec.insert( vec.begin(), rand() );
  }
  printStats(vec);
  vec.push_back(rand() % 100);
  printStats(vec);
  return 0;
}
