#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string Word;
	cout << "Please enter anything: ";
	getline(cin, Word);
	return Word;
}

string InvertWordCase(string Word) {
	for (int i = 0; i < Word.length(); i++) {
		if (isupper(Word[i])) {
			Word[i] = tolower(Word[i]);
		}
		else {
			Word[i] = toupper(Word[i]);
		}
	}
	return Word;
}

int main()
{
	string Str = ReadString();
	cout << "\nString after Inverting All Letters Case:\n";
	cout << InvertWordCase(Str);
}