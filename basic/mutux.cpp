# include <iostream>
# include <tr1/memory>
using namespace std;
class A {
public:
	A() {
		cout << "construct A!!!" << endl;
	}
	;
	~A() {
		cout << "destruct A!!!" << endl;
	}
	;
};
class B: public A {
public:
	B() {
		cout << "construct B!!!" << endl;
	}
	;
	~B() {
		cout << "destruct B!!!" << endl;
	}
	;
};
int main() {
//	B* ptrB0 = new B();
	std::tr1::shared_ptr<B> ptrB1(new B());
}

