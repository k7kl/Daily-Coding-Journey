#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string Word;
	cout << "Please Enter Your String?\n";
	getline(cin, Word);
	return Word;
}

enum enWhatToCount {SmallLetters,CapitalLetters,All};

int CountLetters(string Word, enWhatToCount WhatToCount = All) {
	int Counter = 0;
	switch (WhatToCount)
	{
	case SmallLetters:
		for (int i = 0; i < Word.length(); i++) {
			if (islower(Word[i])) {
				Counter++;
			}
		}
		return Counter;
	case CapitalLetters:
		for (int i = 0; i < Word.length(); i++) {
			if (isupper(Word[i])) {
				Counter++;
			}
		}
		return Counter;
	case All:
		return Word.length();
	}
}

void PrintResult(string Word) {
	cout << "\nString Length = " << CountLetters(Word) << endl;
	cout << "Capital Letters Count = " << CountLetters(Word,CapitalLetters) << endl;
	cout << "Small Letters Count = " << CountLetters(Word, SmallLetters) << endl;
}

int main()
{
	string Word = ReadString();
	PrintResult(Word);
}