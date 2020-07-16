//vector<int> winners;
//winners = Lotto(51, 6);
//random_shuffle()

#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> Lotto(int spots, int takes);
template <class T>
void showVector(std::vector<T> vec);

int main() {
	using namespace std;
	
	vector<int> winners = Lotto(51, 6);

	cout << endl;
	showVector<int>(winners);
}

std::vector<int> Lotto(int spots, int takes)
{
	std::vector<int> all;
	std::vector<int> winners;
	for (int i = 1; i <= spots; i++) {
		all.push_back(i);
	}
	for (int i = 0; i < takes; i++) {
		std::random_shuffle(all.begin(), all.end());
		showVector<int>(all);
		winners.push_back((all.back()));
		all.pop_back();
	}
	return winners;
}

template <class T>
void showVector(std::vector<T> vec) {
	for (auto pr : vec) {
		std::cout << pr << " ";
	}
	std::cout << std::endl;
}