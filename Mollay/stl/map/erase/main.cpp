#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <algorithm>
using std::string;
const int MAX = 26;
const int MAX_NUMBER = 10;

void init(std::map<string, int> & atlas) {
  string letter("A");
  for (unsigned int i = 0; i < MAX; ++i) {
    atlas[letter] = rand() % MAX_NUMBER;
    letter[0]++;
  }
}

void print(const std::map<string, int> & atlas) {
  std::cout << "The map contains:" << std::endl;
  std::map<string, int>::const_iterator ptr = atlas.begin();
  while ( ptr != atlas.end() ) {
    std::cout << '(' << ptr->first  << ", " << ptr->second << ") ";
    ++ptr;
  }
  std::cout << std::endl;
}
void eraseEvens(std::map<string, int> & atlas) {
  for (std::map<string, int>::iterator pos = atlas.begin(); 
       pos != atlas.end(); ) {
    if ( pos->second%2 == 0 ) {
      // erase is a void function; returns nothing
      // According to the standard, pos is undefined after
      //   calling erase; calling ++pos after using erase results 
      //   in undefined behavior. However, pos++ increments pos so
      //   that it points to the next element, but yields a copy
      //   of its original value.
      atlas.erase(pos++);
    }
    else {
      ++pos;
    }
  }

}



int main() {
  std::map<string, int> atlas;
  init(atlas);
  print(atlas);
  atlas["Z"] = atlas["A"];
  print(atlas);
  atlas.erase("A");
  print(atlas);
  eraseEvens(atlas);
  print(atlas);
}
