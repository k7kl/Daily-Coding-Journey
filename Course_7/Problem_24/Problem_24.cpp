#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string Word;
	cout << "Please enter anything: ";
	getline(cin, Word);
	return Word;
}

string LowerFirstLetterOfEachWord(string Word) {
	bool IsFirstLetter = true;

	for (int i = 0; i < Word.length(); i++) {
		if (Word[i] != ' ' && IsFirstLetter) {
			Word[i] = tolower(Word[i]);
			IsFirstLetter = false;
		}

		if (Word[i] == ' ') {
			IsFirstLetter = true;
		}
	}
	return Word;
}

int main()
{
	string Word = ReadString();
	cout << "\nString after conversion:\n";
	cout << LowerFirstLetterOfEachWord(Word);
}