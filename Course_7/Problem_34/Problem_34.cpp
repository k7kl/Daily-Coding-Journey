#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string Word;
	cout << "Please Enter Your String?\n";
	getline(cin, Word);
	return Word;
}

void PrintEachWordInString(string word) {
	string delimter = " ";
	short pos =0;
	string NewWord;

	while ((pos = word.find(delimter)) != string::npos) {
		NewWord = word.substr(0, pos);

		if (NewWord != "") {
			cout << NewWord << endl;
		}
		word.erase(0, pos + delimter.length());
	}
	if (word != "") {
		cout << word;
	}
}


int main() 
{
	string word = ReadString();
	PrintEachWordInString(word);
}