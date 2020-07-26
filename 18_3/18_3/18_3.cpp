#include <iostream>
#include <string>

template<typename T>
long double sum_value(const T& value) {
	long double sum = value;
	return sum;
}

template<typename T, typename... Args>
long double sum_value (T value, const Args&... args) {
	long double sum =  value + sum_value(args...);
	sum_value(args...);
	return sum;
}

int main() {
	std::cout << sum_value(1, 2) << std::endl;
	std::cout << sum_value(1, 2, 3, 4) << std::endl;
	std::cout << sum_value(1, 2,11,12,13,14) << std::endl;

	return 0;
}