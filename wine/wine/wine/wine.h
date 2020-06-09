#ifndef WINE_
#define WINE_
#include <iostream>
#include <valarray>
#include "pair.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
	std::string name;
	PairArray PairObj;
	int noYears;
public:
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);
	void GetBottles();
	std::string& Label();
	int sum();
	void Show();
};

Wine::Wine(const char* l, int y, const int yr[], const int bot[]) : name(l), noYears(y)
{
	ArrayInt tempYr(y), tempBot(y);
	for (int i = 0; i < y; i++)
	{
		tempYr[i] = yr[i];
		tempBot[i] = bot[i];
	}
	PairObj = PairArray(tempYr, tempBot);
}

Wine::Wine(const char* l, int y) : name(l), noYears(y)
{
	ArrayInt tempYr(y), tempBot(y);
	for (int i = 0; i < y; i++)
	{
		tempYr[i] = 0;
		tempBot[i] = 0;
	}
	PairObj = PairArray(tempYr, tempBot);
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
	PairObj.setT1(tempT1);
	PairObj.setT2(tempT2);
}

std::string& Wine::Label()
{
	return name;
}

int Wine::sum()
{
	ArrayInt everyBottle = PairObj.second();
	return everyBottle.sum();

	//return (PairObj.second).sum();
}

#endif // !WINE_

void Wine::Show()
{
	std::cout << "Wine name: " << name <<std::endl;
	for (int i = 0; i < noYears; i++)
	{
		std::cout << "vintage year: " << (PairObj.first())[i] << " - number of bottles: " << (PairObj.second())[i] << std::endl;
	}
	
}