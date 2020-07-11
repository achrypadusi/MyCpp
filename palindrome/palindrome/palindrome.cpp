#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using std::string;

string& simplyString(string& word);
int main()
{
	using namespace std;

	string fileName, word;
	vector<string> allWords;

	cout << endl << "write file name: ";
	cin >> fileName;
	fstream fileObj;
	fileObj.open(fileName, fstream::in);

	while (fileObj >> word)
		allWords.push_back(word);
	fileObj.close();

	for (auto word : allWords) {
		cout << word << endl;
		simplyString(word);
		auto wordRev = word;
		reverse(wordRev.begin(), wordRev.end());
		if ( word == wordRev )
		{
			cout << endl << "yes" << endl;
		} else
			cout << endl << "no" << endl;
	}
	
	getchar();
	getchar();
	
	return 0;
}

string& simplyString(string& word)
{
	string newWord;
	for (char sign : word) {
		if (isalpha(sign)) {
			newWord.push_back(tolower(sign));
			/*if (isupper(sign))
				newWord[i] = tolower(sign);
			else
				newWord[i] = sign;*/
		}
	}
	word = newWord;
	std::cout << "simply string is: " << word << std::endl;
	return word;
}