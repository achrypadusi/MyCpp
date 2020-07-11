#include <iostream>
#include <algorithm>

int reduce(long ar[], int n);

int main()
{
	using namespace std;
	
	long ar[] = { 3, 1, 2 ,3, 7, 1 };
	int sizeAr = sizeof(ar) / sizeof(long);
	cout << "size of array: " << sizeAr << endl;

	cout << "size of reduced: " << reduce(ar, sizeAr) << endl;
}

int reduce(long ar[], int n) {
	std::sort(ar, ar + n);
	long* lastOne = std::unique(ar, ar + n);
	n = lastOne - ar;
	for (int i = 0; i < n; i++)
		std::cout << i << " ";
	std::cout << std::endl;
	return n;
}