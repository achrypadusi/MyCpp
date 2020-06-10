// workmi.cpp -- multiple inheritance
// compile with workermi.cpp
#include <iostream>
#include <cstring>
#include "workermi.h"
#include "QueueTp.h"

const int SIZE = 5;
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;
	Worker* lolas[SIZE];
	Queue<Worker*> qObj(SIZE);
	Worker* tempWorker;
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter s: singer "
			<< "t: singing waiter q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w': lolas[ct] = new Waiter;
			break;
		case 's': lolas[ct] = new Singer;
			break;
		case 't': lolas[ct] = new SingingWaiter;
			break;
		}
		cin.get();
		lolas[ct]->Set();
		tempWorker = lolas[ct];
		qObj.enqueue(tempWorker);
	}
	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}


	cout << "QUEUE!!!" << endl << endl;
	cout << qObj.queuecount() << endl;
	qObj.dequeue(tempWorker);
	tempWorker->Show();
	qObj.dequeue(tempWorker);
	tempWorker->Show();
	qObj.dequeue(tempWorker);
	tempWorker->Show();

	for (i = 0; i < ct; i++)
		delete lolas[i];
	cout << "Bye.\n";
	return 0;
}

//int queuecount() const;
//bool enqueue(const Item& item); // add item to end
//bool dequeue(Item& item); // remove item from front