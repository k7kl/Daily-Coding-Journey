#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string Word;
	cout << "Please Enter Your String?\n";
	getline(cin, Word);
	return Word;
}	

char ReadChar() {
	char Letter;
	cout << "Please Enter a Letter?\n";
	cin >> Letter;
	return Letter;
}

int CountLetter(string Word, char Letter,bool MatchCase = true) {
	int Counter = 0;
	for (int i = 0; i < Word.length(); i++) {
		if (MatchCase) {
			if (Word[i] == Letter) {
				Counter++;
			}
		}
		else {
			if (tolower(Word[i]) == tolower(Letter)) {
				Counter++;
			}
		}
	}
	return Counter;
}

void PrintResult(string Word ,char Letter) {
	cout << "Letter '" << Letter << "' Count = " << CountLetter(Word, Letter, 1) << endl;
	cout << "Letter '" << char(tolower(Letter)) << " or "<< char(toupper(Letter)) << "' Count = " << CountLetter(Word, Letter, 0);

}

int main()
{
	string Word = ReadString();
	char Letter = ReadChar();
	PrintResult(Word,Letter);
}