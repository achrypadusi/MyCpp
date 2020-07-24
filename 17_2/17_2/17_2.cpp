#include <iostream>
#include <typeinfo>

#include "17_2.h"


using std::cout;
using std::endl;

Cpmv::Cpmv(std::string q, std::string z) {
	cout << "constructor qcode " << q << " zcode " << z << endl;
	pi = new Info{ q, z };
};

Cpmv::Cpmv() : Cpmv::Cpmv("", "") {
	cout << "null constructor" << endl;
};

Cpmv::Cpmv(const Cpmv& cp) {
	cout << "copy constructor " << cp.pi->qcode << " " << cp.pi->zcode << endl;
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
};

Cpmv::Cpmv(Cpmv&& mv) {
	cout << "move constructor" << endl;
	pi = new Info;
	pi->qcode = mv.pi->qcode;
	pi->zcode = mv.pi->zcode;
	mv.pi = nullptr;	
};
Cpmv::~Cpmv() {
	cout << "destructor: " << endl;
	delete pi;
}
Cpmv& Cpmv::operator=(const Cpmv& cp){
	cout << "Copy operator: Cpmv& Cpmv::operator=(const Cpmv& cp)" << endl;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	return *this;
}
Cpmv& Cpmv::operator=(Cpmv&& mv){
	cout << "Move operator: Cpmv& Cpmv::operator=(Cpmv&& mv)" << endl;
	pi->qcode = mv.pi->qcode;
	pi->zcode = mv.pi->zcode;
	mv.pi = nullptr;
	return *this;
}
Cpmv Cpmv::operator+(const Cpmv& obj) const {
	cout << "Add operator: Cpmv Cpmv::operator+(const Cpmv& obj) const" << endl;
	auto qcode = pi->qcode + obj.pi->qcode;
	auto zcode = pi->qcode + obj.pi->qcode;
	Cpmv temp(qcode, zcode);
	return temp;
}

void Cpmv::Display() const {
	//cout <<"type name: "<< typeid(*this).name() << endl;
	cout << "DISPLAY - qcode: " << pi->qcode << " zcode: " << pi->zcode << endl;
};
