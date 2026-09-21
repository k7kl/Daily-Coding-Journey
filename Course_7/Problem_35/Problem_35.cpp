#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string input;
	cout << "Please enter your string?" << endl;
	getline(cin, input);
	return input;
}	

int CountWordsInString(string Word) {
	string deli = " ";
	string NewWord;
	short pos;
	short WordCounter = 0;

	while ((pos = Word.find(deli)) != string::npos) {
		NewWord = Word.substr(0, pos);

		if (NewWord != "") {
			WordCounter++;
		}
		Word.erase(0,pos + deli.length());
	}
	if (Word != "") {
		WordCounter++;
	}
	return WordCounter;
}

int main()
{
	string Word = ReadString();
	cout << CountWordsInString(Word);
}