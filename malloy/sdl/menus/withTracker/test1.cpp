#include <cstring>

class Auto: public Vechicle{
public:
	Auto(const Auto& newAuto):Vechicle(newAuto),makeOf(new char[strlen(newAuto.getBuf())]){strcpy(makeOf,newAuto.getBuf);}
	//copy constructor
	
};