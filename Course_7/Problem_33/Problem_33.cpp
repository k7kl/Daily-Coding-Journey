#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string Word;
	cout << "Please Enter Your String?\n";
	getline(cin, Word);
	return Word;
}

bool IsVowel(char Letter) {
	Letter = tolower(Letter);
	switch (Letter)
	{
	case 'a': case 'e': case 'i': case 'o': case 'u':
		return true;
	default:
		return false;
	}
}

void PrintVowelLetters(string Word) {
	cout << "Vowels in string are: ";
	for (int i = 0; i < Word.length(); i++) {
		if (IsVowel(Word[i])) {
			cout << "\t" << Word[i];
		}
	}
}

int main()
{
	string Word = ReadString();
	PrintVowelLetters(Word);
}