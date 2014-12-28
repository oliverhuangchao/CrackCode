#include <iostream>
#include <string>

class A {
public:
  A(const std::string& n) : name(n) {}
  virtual void print() = 0;
  virtual void doSomething() const { 
    std::cout << "something in A" << std::endl; 
  }
  const std::string& getName() const { return name; }
private:
  std::string name;
};

class B : public A {
public:
  B(const std::string& n, int a) : A(n), age(a) {}
  virtual void print() {
    std::cout << getName() << '\t' << age << std::endl;
  }
  virtual void doSomething() const { 
    std::cout << "Nothing in B" << std::endl; 
  }
  int getAge() const { return age; }
private:
  int age;
};

int main() {
  A* b = new B("Abe", 35);
  b->print();
}
