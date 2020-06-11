#ifndef Person_
#define Person_

class Person
{
private:
	enum {fLen = 15, lLen = 30};
	char firstName[fLen];
	char lastName[lLen];
public:
	Person(const char* fName = "no name", const char* lName = "no last name");
	virtual ~Person() {};
	virtual void Show();
	virtual void Set();
};

class Gunslinger : virtual public Person
{
private:
	double drawTime;
	int notches;
public:
	Gunslinger() : Person(), drawTime(0), notches(0) {};
	Gunslinger(const char* fName, const char* lName, double dTime = 10.5, int nt = 6) : Person(fName, lName), drawTime(dTime), notches(nt) {};
	double& draw();
	virtual void Show();
	virtual void Set();
};

class PokerPlayer : virtual public Person
{
	int lastCard;
public:
	PokerPlayer(const char* fName = "no name", const char* lName = "no last name") : Person(fName, lName), lastCard(-1) {};
	virtual int& draw();
};

class BadDude: public Gunslinger, public PokerPlayer
{
public:
	BadDude() : Person(), Gunslinger(), PokerPlayer() {};
	BadDude(const char* fName, const char* lName, double dTime = 13.5, int nt = 7) : Person(fName, lName), Gunslinger(fName, lName, dTime, nt), PokerPlayer(fName, lName) {};
	double& tdraw();
	int& cdraw();
	void Show();
	void Set();
};


#endif // !Person_

