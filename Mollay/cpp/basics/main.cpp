#include <cstdlib>
#include <iostream>

class A{
public:
  A()         { std::cout << "default" << std::endl; }
  A(const A&) { std::cout << "copy" << std::endl; }
};

void f(int y) {
  std::cout << "y is: " << y << std::endl;
  switch (y) {
    case 0:  y++;
    case 1:  y++;
    case 2:  y++;
    default: y++;
  }
  std::cout << "y is: " << y << std::endl;
}

void g(int& x){ x = 0; }
void h(const A& a){}

int main() {
  int x = 99;
  g(x);
  std::cout << "x is: " << x << std::endl;
  A a;
  h( a );

  f( (rand() % 2) ? 1 : 2 );
  int xVel = rand() % 100 + 50;
  int yVel = rand() % 100 + 50;
  xVel = ( xVel % 2 ? xVel : -xVel);
  yVel = ( yVel % 2 ? yVel : -yVel);
  std::cout << "xVel is: " << xVel << std::endl;
  std::cout << "yVel is: " << yVel << std::endl;
}
