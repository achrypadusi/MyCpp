#ifndef DEF_
#define DEF_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void ShowStr(const std::string& p) {
	std::cout << std::endl << p;
}

void GetStrs(std::ifstream& fin, std::vector<std::string>& vistr) {
	if (fin.is_open()) {
		const int sizeSizeT = sizeof(std::size_t);
		char readCharLen[sizeSizeT];
		std::string str;
		for (int i = 0; fin.read(readCharLen, sizeSizeT); i++) {
			int len = std::atoi(readCharLen);
			char* s = new char[len + 1];
			s[len] = '\0';
			if (fin.read(s, len)) {
				vistr.push_back(s);
			}
			delete[] s;
		}
	}
}

//Functor Store

class Store {
private:
	std::ofstream& fo;
public:
	Store(std::ofstream& fout) : fo(fout) {}
	void operator()(const std::string& str);
};

void Store::operator()(const std::string& str) {
	int len = str.size();
	std::string s = std::to_string(len);
	char const* pchar = s.c_str();
	if (fo.is_open()) {
		fo.write(pchar, sizeof(std::size_t));
		fo.write(str.data(), len);
	}
}


#endif // !DEF_
