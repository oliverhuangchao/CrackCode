#include <iostream>
#include <cstring>

class string {
public:
  string() { std::cout << "default" << std::endl; } 
  string(const char *) { std::cout << "convert" << std::endl; } 
  string(const string&) { std::cout << "copy" << std::endl; } 
  string& operator=(const string&) {
    std::cout << "assign" << std::endl;
    return *this;
  }
private:
  char * buf;
};

class Student {
public:
  Student(const char *n) : name(n) { }
private:
  string name;
};

int main() {
  Student bill("bill");
  return 0;
}
