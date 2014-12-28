
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
const int MAX = 20;
const int MAX_NUMBER = 10;

void init(std::vector<int> & vec) {
  for (unsigned int i = 0; i < MAX; ++i) {
    vec.push_back( rand() % MAX_NUMBER );
  }
}

void print(const std::vector<int> & vec) {
  for (unsigned int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i]  << ", ";
  }
  std::cout << std::endl;
}

void eraseEvens(std::vector<int> & vec) {
  std::vector<int>::iterator ptr = vec.begin();
  while ( ptr != vec.end() ) {
    if ( (*ptr) % 2 == 0 ) {
      ptr = vec.erase(ptr);
    }
    else ++ptr;
  }
}

int main() {
  std::vector<int> vec;
  init(vec);
  print(vec);
  eraseEvens(vec);
  print(vec);
}
