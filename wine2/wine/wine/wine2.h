#ifndef WINE2_
#define WINE2_
#include <iostream>
#include <valarray>
#include "pair.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine: private std::string, private Pair<ArrayInt, ArrayInt>
{
private:
	//std::string name;
	//PairArray PairObj;
	int noYears;
public:

	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);
	void GetBottles();
	std::string& Label() const;
	int sum();
	void Show();
};

Wine::Wine(const char* l, int y, const int yr[], const int bot[]) : std::string(l), noYears(y), PairArray()
{
	ArrayInt tempYr(y), tempBot(y);
	for (int i = 0; i < y; i++)
	{
		tempYr[i] = yr[i];
		tempBot[i] = bot[i];
	}
	setT1(tempYr);
	setT2(tempYr);
	//PairArray = PairArray(tempYr, tempBot);
}

Wine::Wine(const char* l, int y) : std::string(l), noYears(y)
{
	ArrayInt tempYr(y), tempBot(y);
	for (int i = 0; i < y; i++)
	{
		tempYr[i] = 0;
		tempBot[i] = 0;
	}
	PairArray(tempYr, tempBot);
}

void Wine::GetBottles()
{
	ArrayInt tempT1(noYears);
	ArrayInt tempT2(noYears);

	for (int i = 0; i < noYears; i++)
	{
		std::cout << "vintage years: ";
		std::cin >> tempT1[i];
		std::cout << "number of bottles: ";
		std::cin >> tempT2[i];
		
	}
	setT1(tempT1);
	setT2(tempT2);
}

std::string& Wine::Label() const
{
	return (std::string&)*this;
}

int Wine::sum()
{
	ArrayInt everyBottle = second();
	return everyBottle.sum();

	//return (PairObj.second).sum();
}

#endif // !WINE_

void Wine::Show()
{
	std::cout << "Wine name: " << (std::string&) * this <<std::endl;
	for (int i = 0; i < noYears; i++)
	{
		std::cout << "vintage year: " << (first())[i] << " - number of bottles: " << (second())[i] << std::endl;
	}
	
}