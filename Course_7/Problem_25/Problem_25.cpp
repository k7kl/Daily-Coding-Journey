#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string Word;
	cout << "Please enter anything: ";
	getline(cin, Word);
	return Word;
}

string LowerWord(string Word) {
	for (int i = 0; i < Word.length(); i++) {
		Word[i] = tolower(Word[i]);
	}
	return Word;
}

string UpperWord(string Word) {
	for (int i = 0; i < Word.length(); i++) {
		Word[i] = toupper(Word[i]);
	}
	return Word;
}

void PrintWordInUpercaseAndLowerCase(string Word) {
	cout << "String after Upper: " << endl << UpperWord(Word) << endl << endl;
	cout << "String after Lower: " << endl << LowerWord(Word) << endl << endl;

}

int main()
{
	PrintWordInUpercaseAndLowerCase(ReadString());
}