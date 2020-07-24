#include <iostream>
#include "17_2.h"

int main() {
	using std::cout;
	using std::endl;

	Cpmv obj1;
	Cpmv obj2("abc", "def");
	Cpmv obj3(obj2);

	obj1.Display();
	obj2.Display();
	obj3.Display();

	Cpmv obj5 = obj2 + obj3;
	obj5.Display();

	obj1 = obj2;
	obj1.Display();
	obj1 = obj2 + obj3;
	obj1.Display();

	cout << "empty line" << endl;

	return 0;
}
