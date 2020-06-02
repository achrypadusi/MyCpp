// usedma.cpp -- inheritance, friends, and DMA
// compile with dma.cpp
#include <iostream>
#include "dma.h"
int main()
{
	using std::cout;
	using std::endl;
	/*baseDMA shirt("Portabelly", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);
	cout << "Displaying baseDMA object:\n";
	shirt.view();
	//cout << shirt << endl;
	cout << "Displaying lacksDMA object:\n";
	balloon.view();
	//cout << balloon << endl;
	cout << "Displaying hasDMA object:\n";
	map.view();
	//cout << map << endl;
	lacksDMA balloon2(balloon);
	cout << "Result of lacksDMA copy:\n";
	balloon2.view();
	//cout << balloon2 << endl;
	hasDMA map2;
	map2 = map;
	cout << "Result of hasDMA assignment:\n";
	map2.view();*/
	//cout << map2 << endl;

	cout << "Select class: " << endl;
	cout << "baseDMA - 1" << endl << "lackDMA - 2" << endl << "hasDMA - 3" << endl;
	char option;
	while (option = std::cin.get(), option != 'q')
	{
		switch (option)
		{
		case '1':
		{
			cout << "baseDMA" << endl;
			baseDMA* shirt = new baseDMA("Portabelly", 8);
			shirt->view();
			delete shirt;
			break;
		}
		case '2':
		{
			cout << "lackDMA" << endl;
			lacksDMA* balloon = new lacksDMA("red", "Blimpo", 4);
			balloon->view();
			delete balloon;
			break;
		}
		case '3':
		{
			cout << "hasDMA" << endl;
			hasDMA* map = new hasDMA("Mercator", "Buffalo Keys", 5);
			map->view();
			delete map;
			break;
		}
		default:
			cout << "wrong option" << endl;
		}
	}
	return 0;
}