#include <cstdlib>
#include <iostream>
#include <list>

void init(std::list<int>& craigsList) {
  for (unsigned int i = 0; i < 100; ++i) {
    craigsList.push_back( rand() % 100 );
  }
}

void removeEvens(std::list<int>& craigsList) {
  std::list<int>::iterator ptr = craigsList.begin();
  while ( ptr != craigsList.end() ) {
    if ( *ptr % 2 == 0 ) {
      ptr = craigsList.erase(ptr);
    }
    else ++ptr;
  }
}

void print(const std::list<int>& craigsList) {
  std::list<int>::const_iterator ptr = craigsList.begin();
  while ( ptr != craigsList.end() ) {
    std::cout << *ptr << std::endl;
    ++ptr;
  }
}

int main() {
  std::list<int> craigsList;
  init(craigsList);
  removeEvens(craigsList);
  print(craigsList);
  //std::cout << craigsList.capacity() << std::endl;
  std::cout << craigsList.size() << std::endl;
}
