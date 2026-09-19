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

	switch (Letter) {
	case 'a': case 'e': case 'i': case 'o': case 'u':
		return true;
	default:
		return false;
	}
}

int CountVowelLetter(string Word) {
	int Counter=0;
	for (int i = 0; i < Word.length(); i++) {
		if (IsVowel(Word[i])) {
			Counter++;
		}
	}
	return Counter;
}

void DisplayVowelCount(int VowelCount) {
	cout << "\nNumber of vowels is: " << VowelCount << endl;
}

int main()
{
	string Word = ReadString();
	DisplayVowelCount(CountVowelLetter(Word));
}