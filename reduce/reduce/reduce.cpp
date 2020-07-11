#include <iostream>
#include <algorithm>

template <typename T>
int reduce(T ar[], int n);

int main()
{
	using namespace std;
	
	double ar[] = { 3, 1, 2 ,3, 7.2, 1 };
	int sizeAr = sizeof(ar) / sizeof(double);
	cout << "size of array: " << sizeAr << endl;

	cout << "size of reduced: " << reduce(ar, sizeAr) << endl;
}

template <typename T>
int reduce(T ar[], int n) {
	std::sort(ar, ar + n);
	T* lastOne = std::unique(ar, ar + n);
	n = lastOne - ar;
	for (int i = 0; i < n; i++)
		std::cout << ar[i] << " ";
	std::cout << std::endl;
	return n;
}