#include <iostream>
using namespace std;

string RemovePunctuationsFormStringUsingNewString(string Word) {
	string NewString = "";
	for (int i = 0; i < Word.length(); i++) {
		if (!ispunct(Word[i])) {
			NewString += Word[i];
		}
	}
	return NewString;
}

int main()
{
	string Word = "Hello,,, My name is Abdulrazaq. he's Mohammed.";
	Word = RemovePunctuationsFormStringUsingNewString(Word);
	cout << Word;
}