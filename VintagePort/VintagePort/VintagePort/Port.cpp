#include "port.h"
#pragma warning(disable : 4996)

using namespace std;

char* Port::createDynChar(const char* newString)
{
	char* dynArr = new char[strlen(newString) + 1];
	std::strcpy(dynArr, newString);
	return dynArr;
}

Port::Port(const char* br, const char* st, int b)
{
	//brand = new char(strlen(br) + 1);
	//strcpy(brand, br);
	brand = createDynChar(br);
	std::strcpy(style, st);
	bottles = b;
}
Port::Port(const Port& p)
{
	brand = new char[strlen(p.brand) + 1];
	std::strcpy(brand, p.brand);
	std::strcpy(style, p.style);
	bottles = p.bottles;
}
Port& Port::operator=(const Port& p)
{
	if (this == &p)
	{
		return *this;
	}
	delete[] brand;
	brand = new char[strlen(p.brand) + 1];
	std::strcpy(brand, p.brand);
	std::strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}
Port& Port::operator+=(int b)
{
	bottles += b;
	return *this;
}
Port& Port::operator-=(int b)
{
	bottles -= b;
	return *this;
}
void Port::Show() const
{
	cout << "Brand: " << brand << endl;
	cout << "Kind: " << style << endl;
	cout << "Bottles: " << bottles << endl;
}
ostream& operator<<(ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles << endl;
	return os;
}


//Class VintagePort
VintagePort::VintagePort()
{
	VintagePort("none", 0, "none", 0);
}
VintagePort::VintagePort(const char* br, int b, const char* nn, int y) : Port(br,"none",b)
{
	nickname = new char[strlen(nn) + 1];
	std::strcpy(nickname, br);
	year = y;
}
VintagePort::VintagePort(const VintagePort& vp) : Port(vp)
{
	nickname = createDynChar(vp.nickname);
	year = vp.year;
}
VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	if (this == &vp)
	{
		return *this;
	}
	delete[] nickname;
	nickname = createDynChar(vp.nickname);
	year = vp.year;
	return *this;
}
