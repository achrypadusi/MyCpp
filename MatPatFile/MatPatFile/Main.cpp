#include <set>
#include <iostream>
#include <fstream>
#include <string>

int main() {
	using namespace std;

	set<string> matSet;
	set<string> patSet;
	set<string> joinSet;
	string tempString;

	ifstream matStream;
	matStream.open("mat.txt");
	while ( std::getline(matStream, tempString) && tempString.size() > 0 ) {
		cout << tempString;
		matSet.insert(tempString);
	}
	matStream.close();
	cout << endl;

	fstream patStream;
	patStream.open("pat.txt", ios::in);
	while (std::getline(patStream, tempString) && tempString.size() > 0) {
		cout << tempString;
		patSet.insert(tempString);
	}
	patStream.close();
	cout << endl;
	
	fstream joinStream;
	joinStream.open("join.txt", ios::out);

	joinSet.insert(matSet.begin(), matSet.end());
	joinSet.insert(patSet.begin(), patSet.end());
	for (string name : joinSet) {
		cout << name << endl;
		joinStream << name << endl;
	}
	joinStream.close();

	getchar();

	return 0;
}