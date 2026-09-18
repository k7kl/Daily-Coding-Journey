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

int CountLetter(string Word, char Letter) {
	int Counter=0;
	for (int i = 0; i < Word.length(); i++) {
		if (Word[i] == Letter) {
			Counter++;
		}
		
	}
	return Counter;
}

void PrintResult(char Letter,int Counter) {
	cout << "Letter '" << Letter << "' Count = " << Counter;
}

int main()
{
	string Word = ReadString();
	char Letter = ReadChar();
	PrintResult(Letter, CountLetter(Word, Letter));
}