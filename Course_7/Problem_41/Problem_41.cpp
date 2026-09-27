#include <iostream>
using namespace std;

void ReplaceWordInStringUsingBuiltInFunction(string& Word, string WordToReplace, string WantedWord) {
	int pos = Word.find(WordToReplace);

	while (pos!= string::npos) {

		Word.replace(pos, WordToReplace.length(), WantedWord);

		pos = Word.find(WordToReplace,pos + WantedWord.length());
	}
}

int main()
{
	string Word = "Welcome To Yemen , Yemen is a nice country.";
	ReplaceWordInStringUsingBuiltInFunction(Word,"Yemen","South Yemen");
	cout << Word;
}