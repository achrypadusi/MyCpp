#include <string>
#include <iostream>

using std::string;

string& simplyString(string& word);
int main()
{
	using namespace std;

	string word, wordRev;

	cout << endl << "write word to check palindrome. Write q to exit: ";
	while (getline(cin,word) && word != "q") {
		simplyString(word);
		wordRev = word;
		reverse(wordRev.begin(), wordRev.end());
		if ( word == wordRev )
		{
			cout << endl << "yes" << endl;
		} else
			cout << endl << "no" << endl;
		cout << endl << "write word to check palindrome. Write empty to exit: ";
	}
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