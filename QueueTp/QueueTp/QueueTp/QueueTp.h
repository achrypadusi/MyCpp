// queue.h -- interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_
// This queue will contain Customer items
/*class Customer
{
private:
	long arrive; // arrival time for customer
	int processtime; // processing time for customer
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};
typedef Customer Item;*/

template <typename Item>
class Queue
{
private:
	// class scope definitions
	// Node is a nested structure definition local to this class
	struct Node { Item item; struct Node* next; };
	enum { Q_SIZE = 10 };
	// private class members
	Node* front; // pointer to front of Queue
	Node* rear; // pointer to rear of Queue
	int items; // current number of items in Queue
	const int qsize; // maximum number of items in Queue
	// preemptive definitions to prevent public copying
	Queue(const Queue& q) : qsize(0) { }
	Queue& operator=(const Queue& q) { return *this; }
public:
	Queue(int qs = Q_SIZE); // create queue with a qs limit
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item); // add item to end
	bool dequeue(Item& item); // remove item from front
	//Item& showTop(Item& item);
};

#include <cstdlib> // (or stdlib.h) for rand()
// Queue methods
template <typename Item>
Queue<Item>::Queue(int qs) : qsize(qs)
{
	front = rear = NULL; // or nullptr
	items = 0;
}
template <typename Item>
Queue<Item>::~Queue()
{
	Node* temp;
	while (front != NULL) // while queue is not yet empty
	{
		temp = front; // save address of front item
		front = front->next;// reset pointer to next item
		delete temp; // delete former front
	}
}
template <typename Item>
bool Queue<Item>::isempty() const
{
	return items == 0;
}
template <typename Item>
bool Queue<Item>::isfull() const
{
	return items == qsize;
}
template <typename Item>
int Queue<Item>::queuecount() const
{
	return items;
}
// Add item to queue
template <typename Item>
bool Queue<Item>::enqueue(const Item& item)
{
	if (isfull())
		return false;
	Node* add = new Node; // create Item
	// on failure, new throws std::bad_alloc exception
	add->item = item; // set Item pointers
	add->next = NULL; // or nullptr;
	items++;
	if (front == NULL) // if queue is empty,
		front = add; // place item at front
	else
		rear->next = add; // else place at rear
	rear = add; // have rear point to new Item
	return true;
}
// Place front item into item variable and remove from queue
template <typename Item>
bool Queue<Item>::dequeue(Item& item)
{
	if (front == NULL)
		return false;
	item = front->item; // set item to first item in queue
	items--;
	Node* temp = front; // save location of first item
	front = front->next; // reset front to next item
	delete temp; // delete former first item
	if (items == 0)
		rear = NULL;
	return true;
}

/*
// customer method
// when is the time at which the customer arrives
// the arrival time is set to when and the processing
// time set to a random value in the range 1 - 3
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}
*/
#endif