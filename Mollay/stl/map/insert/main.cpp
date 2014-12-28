#include <string>
#include <iostream>
#include <map>

void print(const std::map<std::string, int>& myMap) {
  std::map<std::string, int>::const_iterator ptr = myMap.begin();
  while ( ptr != myMap.end() ) {
    std::cout << ptr->first << ", " << ptr->second << std::endl;
    ++ptr;
  }
}


int main() {
  std::map<std::string, int> myMap;
  myMap["horse"] = 24;
  myMap["hank"] = 160;
  myMap["cat"] = 34;
  myMap["rabbit"] = 94;
  myMap["rabbit"] = 99;
  myMap["hank"] = 260;
  print(myMap);
}
