
#include "emp.h"
using std::cout;
using std::cin;
using std::endl;

// robimy confilct
abstr_emp::abstr_emp() : fname(""), lname(""), job("") {};
abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j) : fname(fn), lname(ln), job(j) {};
void abstr_emp::ShowAll() const
{
	cout << "first name: " << fname << "\tlast name: " << lname << "\tjob: " << job << endl;
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
	os << e.fname << " " << e.lname << endl;
	return os;
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
	cout << "inchargeof: " << inchargeof << endl;
}
void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "inchargeof number: ";
	cin >> inchargeof;
}

//class fink
fink::fink() : abstr_emp(), reportsto("") {};
fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo) : abstr_emp(fn, ln, j), reportsto(rpo) {};
fink::fink(const abstr_emp& e, const std::string& rpo) : abstr_emp(e), reportsto(rpo) {}
fink::fink(const fink& e) : abstr_emp(e), reportsto(e.reportsto) {}
void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "reportsto: " << reportsto << endl;
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
	cout << "inchargeof: " << InChargeOf() << endl;
	cout << "reportsto: " << ReportsTo() << endl;
}
void highfink::SetAll()
{
	manager::SetAll();
	Setreportsto();
}