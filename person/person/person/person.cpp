#include "person.h"
#include <iostream>
#include <cstdlib> // for rand(), srand()
#include <ctime> // for time()

#pragma warning(disable : 4996)

using std::cout;
using std::endl;
using std::cin;

//class Person
Person::Person(const char* fName, const char* lName)
{
	strcpy(firstName, fName);
	strcpy(lastName, lName);
}
void Person::Show()
{
	std::cout << "first name: " << firstName << "\t" << "last name: " << lastName << std::endl;
}

void Person::Set()
{
	cout << "type first name: " << endl;
	cin >> firstName;
	cout << "type last name: " << endl;
	cin >> lastName;
}

//class Gunslinger
double& Gunslinger::draw()
{
	return drawTime;
}
void Gunslinger::Show()
{
	Person::Show();
	std::cout << "draw time: " << drawTime << "\t" << "notches: " << notches << std::endl;
}

void Gunslinger::Set()
{
	Person::Set();
	cout << "type draw time: " << endl;
	cin >> drawTime;
	cout << "type notches: " << endl;
	cin >> notches;
}


//class PokerPlayer
int& PokerPlayer::draw()
{
	std::srand(std::time(0));
	lastCard = (std::rand() % 52);
	return lastCard;
}

//class BadDude

int& BadDude::cdraw()
{
	return PokerPlayer::draw();
}
double& BadDude::tdraw()
{
	return Gunslinger::draw();
}

void BadDude::Show()
{
	Gunslinger::Show();
	std::cout << "last card: "<< cdraw() << std::endl;
}

void BadDude::Set()
{
	Gunslinger::Set();
}