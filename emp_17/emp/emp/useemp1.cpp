#include <iostream>
#include <fstream>
#include <vector>
#include "emp.h"

abstr_emp* selectMode();
int main(void)
{
	using namespace std;

	{
		string fileName;
		cout << "write file name: ";
		cin >> fileName;
		abstr_emp* empP = selectMode();
		
		empP->ReadFile(fileName);
		empP->SetAll();
		empP->AppendFile(fileName);
		empP->ReadFile(fileName);

		delete empP;
	}

	return 0;
}

abstr_emp* selectMode() {
	int classNumber = 1;
	std::cout << "select class: employee = 1, manager = 2, fink = 3, highfink = 4  :";
	std::cin >> classNumber;
	abstr_emp* temp;
	switch (classNumber) {
		case 1:
			temp = new employee;
			break;
		case 2:
			temp = new manager;
			break;
		case 3:
			temp = new fink;
			break;
		case 4:
			temp = new highfink;
			break;
		default:
			std::cout << "wrong class number. Default employee" << std::endl;
			temp = new employee;
	}
	return temp;
}

