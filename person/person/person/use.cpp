
// workmi.cpp -- multiple inheritance
// compile with workermi.cpp
#include <iostream>
#include <cstring>
#include "person.h"
const int SIZE = 5;
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;
	Person* everybody[SIZE];
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "g: Gunslinger p: PokerPlayer "
			<< "b: BadDude q: quit\n";
		cin >> choice;
		while (strchr("gpbq", choice) == NULL)
		{
			cout << "Please enter a g, p, b, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'g': everybody[ct] = new Gunslinger;
			break;
		case 'p': everybody[ct] = new PokerPlayer;
			break;
		case 'b': everybody[ct] = new BadDude;
			break;
		}
		cin.get();
		everybody[ct]->Set();
	}
	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		everybody[i]->Show();
	}
	
	cout << "wait" << endl;
	for (i = 0; i < ct; i++)
		delete everybody[i];
	cout << "Bye.\n";
	return 0;
}
