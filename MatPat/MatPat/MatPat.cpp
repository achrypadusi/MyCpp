#include <iostream>
#include <set>
#include <string>
#include <typeinfo>  

using namespace std;

int main() {
	set<string> pat, mat, all;
	string temp;

	cout << "enter pat list: " << endl;
	while (getline(cin, temp) && temp != "quit") {
		pat.insert(temp);
	}
	cout << "enter mat list: " << endl;
	while (getline(cin, temp) && temp != "quit") {
		mat.insert(temp);
	}
	all = pat;
	all.insert(mat.begin(), mat.end());

	for (auto x : all) {
		cout << x << " ";
	}

	cout << endl;
	cout << typeid(all).name() << endl;
}