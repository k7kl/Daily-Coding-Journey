#include <iostream>
using namespace std;

void PrintFirstLetterOfEachWord(string Word) {
	bool IsFirstLetter = true;

	for (int i = 0; i < Word.length(); i++) {
		if (IsFirstLetter && Word[i] != ' ') {
			cout << Word[i] << "\t";
			IsFirstLetter = false;
		}
		if (Word[i] == ' ')
			IsFirstLetter = true;
	}
}



int main()
{
	PrintFirstLetterOfEachWord(" Abdulrazaq Saleh Ahmed Saleh  ");
}