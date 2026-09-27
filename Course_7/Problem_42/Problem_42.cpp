#include <iostream>
#include <vector>
using namespace std;

vector <string> SplitStringToVector(string Word, string Delimiter) {
	vector <string> vString;

	int pos;
	string NewWord = "";
	while ((pos = Word.find(Delimiter)) != string::npos)
	{
		NewWord = Word.substr(0, pos);

		if (NewWord != "") {
			vString.push_back(NewWord);
		}
		Word.erase(0, pos + Delimiter.length());
	}
	if (Word != "") {
		vString.push_back(Word);
	}
	return vString;
}

string StringToLowerCase(string word) {
	for (int i = 0; i < word.length(); i++) {
		word[i] = tolower(word[i]);
	}
	return word;
}

string ChangeWordInString(string Word, string WordToChange, string NewWord,bool MatchCase = true) {
	vector <string> vString = SplitStringToVector(Word," ");
	vector <string>::iterator itr = vString.begin();
	string WordAfterChanged = "";

	if (MatchCase) {
		while (itr != vString.end()) {

			if (*itr == WordToChange) {
				*itr = NewWord;
			}
			WordAfterChanged += *itr + " ";
			itr++;
		}
	}
	else {
		string WordToChangeInLowerCase = StringToLowerCase(WordToChange);
		while (itr != vString.end()) {
			if (StringToLowerCase(*itr) == WordToChangeInLowerCase) {
				*itr = NewWord;
			}

			WordAfterChanged += *itr + " ";
			itr++;
		}
	}
	return WordAfterChanged.substr(0, WordAfterChanged.length() - 1);
}

int main()
{
	string Word = "Ahmed Mohammed ali Khaled ali";
	Word = ChangeWordInString(Word,"ALI","ABDULRAZAQ",false);
	cout << Word;
}