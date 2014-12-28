#include <iostream>
using std::cout; using std::endl;

class Student {
public:
  Student() : gpa(0) {}
  Student(const float g)    : gpa(g) { }
  Student(const Student& s) : gpa(s.gpa) {}

  float getGpa() const      { return gpa; }
  void setGpa(const int g)  { gpa = g; }  
  void display() const;
  
private:
  float gpa;
};
