// workermi.h -- working classes with MI
#ifndef WORKERMI_H_
#define WORKERMI_H_
#include <string>
class Worker // an abstract base class
{
private:
	std::string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker() : fullname("no one"), id(0L) {}
	Worker(const std::string& s, long n)
		: fullname(s), id(n) {}
	virtual ~Worker() = 0; // pure virtual function
	virtual void Set() = 0;
	virtual void Show() const = 0;
};
class Waiter : virtual public Worker
{
private:
	int panache;
protected:
	void Data() const;
	void Get();
public:
	Waiter() : Worker(), panache(0) {}
	Waiter(const std::string& s, long n, int p = 0)
		: Worker(s, n), panache(p) {}
	Waiter(const Worker& wk, int p = 0)
		: Worker(wk), panache(p) {}
	void Set();
	void Show() const;
};
class Singer : virtual public Worker
{
protected:
	enum {
		other, alto, contralto, soprano,
		bass, baritone, tenor
	};
	enum { Vtypes = 7 };
	void Data() const;
	void Get();
private:
	const char* pv[Vtypes] = { "other", "alto", "contralto",
"soprano", "bass", "baritone", "tenor" }; // string equivs of voice types
	int voice;
public:
	Singer() : Worker(), voice(other) {}
	Singer(const std::string& s, long n, int v = other)
		: Worker(s, n), voice(v) {}
	Singer(const Worker& wk, int v = other)
		: Worker(wk), voice(v) {}
	void Set();
	void Show() const;
};
// multiple inheritance
class SingingWaiter : public Singer, public Waiter
{
protected:
	void Data() const;
	void Get();
public:
	SingingWaiter() {}
	SingingWaiter(const std::string& s, long n, int p = 0,
		int v = other)
		: Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
	SingingWaiter(const Worker& wk, int p = 0, int v = other)
		: Worker(wk), Waiter(wk, p), Singer(wk, v) {}
	SingingWaiter(const Waiter& wt, int v = other)
		: Worker(wt), Waiter(wt), Singer(wt, v) {}
	SingingWaiter(const Singer& wt, int p = 0)
		: Worker(wt), Waiter(wt, p), Singer(wt) {}
	void Set();
	void Show() const;
};



#include <iostream>
using std::cout;
using std::cin;
using std::endl;
// Worker methods
Worker::~Worker() { }
// protected methods
void Worker::Data() const
{
	cout << "Name: " << fullname << endl;
	cout << "Employee ID: " << id << endl;
}
void Worker::Get()
{
	getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}
// Waiter methods
void Waiter::Set()
{
	cout << "Enter waiter's name: ";
	Worker::Get();
	Get();
}
void Waiter::Show() const
{
	cout << "Category: waiter\n";
	Worker::Data();
	Data();
}
// protected methods
void Waiter::Data() const
{
	cout << "Panache rating: " << panache << endl;
}
void Waiter::Get()
{
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}
// Singer methods
void Singer::Set()
{
	cout << "Enter singer's name: ";
	Worker::Get();
	Get();
}
void Singer::Show() const
{
	cout << "Category: singer\n";
	Worker::Data();
	Data();
}
// protected methods
void Singer::Data() const
{
	cout << "Vocal range: " << pv[voice] << endl;
}
void Singer::Get()
{
	cout << "Enter number for singer's vocal range:\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << '\n';
	cin >> voice;
	while (cin.get() != '\n')
		continue;
}
// SingingWaiter methods
void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}
void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}
void SingingWaiter::Set()
{
	cout << "Enter singing waiter's name: ";
	Worker::Get();
	Get();
}
void SingingWaiter::Show() const
{
	cout << "Category: singing waiter\n";
	Worker::Data();
	Data();
}
#endif