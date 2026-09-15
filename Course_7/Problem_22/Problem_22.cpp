#include <iostream>
using namespace std;

//void PrintFirstLetterOfEachWord(string Word) {
//	for (int i = 0; i < Word.length(); i++) {	
//		if (i == 0) {
//			cout << Word[i] << "\t";
//		}
//		else if (Word[i] == ' ' && Word[i + 1] != ' ') {
//			cout << Word[i + 1] << "\t";
//		}
//	}
//}

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
	PrintFirstLetterOfEachWord(" Abdulrazaq   Saleh   Ahmed   Saleh  ");
}