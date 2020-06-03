#include "port.h"

int main()
{
	Port P1;
	Port P2("lajba", "morski", 20);
	Port P3 = P2;
	P3 += 3;
	P1 = P3;
	P1.Show();
	P2.Show();
	P3.Show();
	cout << P1;
	cout << P2;
	cout << P3;

	cout << endl << endl;

	VintagePort VP1;
	VintagePort VP2("katamaran", 30,"staruszka",  1900);
	VintagePort VP3 = VP2;
	VP3 += 3;
	VP1 = VP3;
	VP1.Show();
	VP2.Show();
	VP3.Show();
	cout << VP1;
	cout << VP2;
	cout << VP3;
}