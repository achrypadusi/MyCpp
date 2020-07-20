#include <fstream>
#include <string>
#include <vector>
#include "emp.h"
using std::cout;
using std::cin;
using std::endl;

std::vector<std::string> split(const std::string& str, const std::string& delim);

// abstr_emp
abstr_emp::abstr_emp() : fname(""), lname(""), job("") {};
abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j) : fname(fn), lname(ln), job(j) {};
void abstr_emp::ShowAll() const
{
	cout << "first name: " << fname << "\tlast name: " << lname << "\tjob: " << job;
}
void abstr_emp::SetAll()
{
	cout << "set values" << endl;
	cout << "first name: ";
	cin >> fname;
	cout << "last name: ";
	cin >> lname;
	cout << "job: ";
	cin >> job;
}
std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << e.fname << " " << e.lname;
	return os;
}
void abstr_emp::AppendFile(std::string& fileName) const {
	std::fstream userStream;
	userStream.open(fileName, std::ios::out | std::ios::app);
	if (!userStream.is_open()) {
		userStream.clear();
		userStream.close();
		std::cerr << "can't open file " << fileName << endl;
		getchar();
		return;
	}
	userStream << endl << fname << ";" << lname << ";" << job;
	userStream.close();
}

void abstr_emp::ReadFile(std::string& fileName) {
	std::string oneLine;
	std::fstream userStream(fileName, std::ios::in);
	if (!userStream.is_open()) {
		userStream.close();
		std::cerr << "can't open file " << fileName << endl;
	}
	std::string delim = ";";
	while ( std::getline(userStream, oneLine) && oneLine.size() > 0 ) {
		std::vector<std::string> vec = split(oneLine, ";");
		fname = vec[0];
		lname = vec[1];
		job = vec[2];
		this->ShowAll();
		cout << endl;
	}
	userStream.close();
}
std::string abstr_emp::ReturnAll() const
{
	std::string allInfo = "first name: " + fname + "\tlast name: " + lname + "\tjob: " + job;
	return allInfo;
}


// employee
employee::employee() : abstr_emp() {};
employee::employee(const std::string& fn, const std::string& ln, const std::string& j) : abstr_emp(fn, ln, j) {};
void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}
void employee::SetAll()
{
	abstr_emp::SetAll();
}

// manager
manager::manager() : abstr_emp(), inchargeof(0) {};
manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico) {};
manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico) {}
manager::manager(const manager& m) : abstr_emp(m), inchargeof(m.inchargeof) {}
void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "\tinchargeof: " << inchargeof;
}
void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "inchargeof number: ";
	cin >> inchargeof;
}
void manager::ReadFile(std::string& fileName) {
	std::string oneLine;
	std::fstream userStream(fileName, std::ios::in);
	if (!userStream.is_open()) {
		userStream.close();
		std::cerr << "can't open file " << fileName << endl;
	}
	std::string delim = ";";
	while (std::getline(userStream, oneLine) && oneLine.size() > 0) {
		std::vector<std::string> vec = split(oneLine, ";");
		fname = vec[0];
		lname = vec[1];
		job = vec[2];
		inchargeof = std::stoi(vec[3]);
		this->ShowAll();
		cout << endl;
	}
	userStream.close();
}
void manager::AppendFile(std::string& fileName) const {
	std::fstream userStream;
	userStream.open(fileName, std::ios::out | std::ios::app);
	if (!userStream.is_open()) {
		userStream.clear();
		userStream.close();
		std::cerr << "can't open file " << fileName << endl;
		getchar();
		return;
	}
	userStream << endl << fname << ";" << lname << ";" << job << ";" << inchargeof;
	userStream.close();
}

//class fink
fink::fink() : abstr_emp(), reportsto("") {};
fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo) : abstr_emp(fn, ln, j), reportsto(rpo) {};
fink::fink(const abstr_emp& e, const std::string& rpo) : abstr_emp(e), reportsto(rpo) {}
fink::fink(const fink& e) : abstr_emp(e), reportsto(e.reportsto) {}
void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "\treportsto: " << reportsto;
}
void fink::SetAll()
{
	abstr_emp::SetAll();
	Setreportsto();
}
void fink::Setreportsto()
{
	cout << "reportsto: ";
	cin >> reportsto;
}
void fink::ReadFile(std::string& fileName) {
	std::string oneLine;
	std::fstream userStream(fileName, std::ios::in);
	if (!userStream.is_open()) {
		userStream.close();
		std::cerr << "can't open file " << fileName << endl;
	}
	std::string delim = ";";
	while (std::getline(userStream, oneLine) && oneLine.size() > 0) {
		std::vector<std::string> vec = split(oneLine, ";");
		fname = vec[0];
		lname = vec[1];
		job = vec[2];
		reportsto = vec[4];
		this->ShowAll();
		cout << endl;
	}
	userStream.close();
}
void fink::AppendFile(std::string& fileName) const {
	std::fstream userStream;
	userStream.open(fileName, std::ios::out | std::ios::app);
	if (!userStream.is_open()) {
		userStream.clear();
		userStream.close();
		std::cerr << "can't open file " << fileName << endl;
		getchar();
		return;
	}
	userStream << endl << fname << ";" << lname << ";" << job << ";" << ""<< ";" << reportsto;
	userStream.close();
}

//class highfink
highfink::highfink() : abstr_emp(), manager(), fink() {}
highfink::highfink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo,
	int ico) : abstr_emp(fn, ln, j), manager(), fink(fn, ln, j, rpo) {}
highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo) {}
highfink::highfink(const fink& f, int ico) : abstr_emp(f), manager(f, ico), fink(f) {}
highfink::highfink(const manager& m, const std::string& rpo) : abstr_emp(m), manager(m), fink(m, rpo) {}
highfink::highfink(const highfink& h) : abstr_emp(h), manager(h), fink(h) {}
void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "\tinchargeof: " << InChargeOf();
	cout << "\treportsto: " << ReportsTo();
}
void highfink::SetAll()
{
	manager::SetAll();
	Setreportsto();
}
void highfink::ReadFile(std::string& fileName) {
	std::string oneLine;
	std::fstream userStream(fileName, std::ios::in);
	if (!userStream.is_open()) {
		userStream.close();
		std::cerr << "can't open file " << fileName << endl;
	}
	std::string delim = ";";
	while (std::getline(userStream, oneLine) && oneLine.size() > 0) {
		std::vector<std::string> vec = split(oneLine, ";");
		fname = vec[0];
		lname = vec[1];
		job = vec[2];
		inchargeof = std::stoi(vec[3]);
		reportsto = vec[4];
		this->ShowAll();
		cout << endl;
	}
	userStream.close();
}
void highfink::AppendFile(std::string& fileName) const {
	std::fstream userStream;
	userStream.open(fileName, std::ios::out | std::ios::app);
	if (!userStream.is_open()) {
		userStream.clear();
		userStream.close();
		std::cerr << "can't open file " << fileName << endl;
		getchar();
		return;
	}
	userStream << endl << fname << ";" << lname << ";" << job << ";" << inchargeof << ";" << reportsto;
	userStream.close();
}




std::vector<std::string> split(const std::string& str, const std::string& delim)
{
	std::vector<std::string> tokens = { "","","","","" };
	size_t prev = 0, pos = 0;
	int tokenPos = 0;
	do
	{
		pos = str.find(delim, prev);
		if (pos == std::string::npos) pos = str.length();
		std::string token = str.substr(prev, pos - prev);
		if (!token.empty())
			//tokens.push_back(token);
			tokens[tokenPos] = token;
		//else
			//tokens.push_back("");
		prev = pos + delim.length();
		tokenPos++;
	} while (pos < str.length() && prev < str.length() && tokenPos < 5);
	return tokens;
}