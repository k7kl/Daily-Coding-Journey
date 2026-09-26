#include <iostream>
#include <vector>
using namespace std;

//OLD SOLUTION 

//string ReverseWord(string Word) {
//	string ReverseWord = "";
//	int movetimes = 0;
//	for (int i = Word.length()-1; i >= 0; i--) {
//		movetimes++;
//		if (Word[i] == ' ') {
//			for (int j = i+1; j < movetimes+i; j++) {
//				ReverseWord += Word[j];
//			}
//			ReverseWord += " ";
//			movetimes = 0;
//		}
//	}
//	for (int i = 0; i < Word.length(); i++) {
//		if (Word[i] != ' ') {
//			ReverseWord += Word[i];
//		}
//		else {
//			break;
//		}
//	}
//	return ReverseWord;
//}


//string ReverseWord(string Word) {
//	string ReverseWord = "";
//	string delim = " ";
//	int pos;
//
//	while ((pos = Word.find(delim)) != string::npos) {
//		string rWord = Word.substr(0,pos);
//		if (rWord != "") {
//			ReverseWord += ReverseSingleWord(rWord);
//			ReverseWord += " ";
//		}
//		Word.erase(0,pos+delim.length());
//	}
//	if (Word != "") {
//		ReverseWord += ReverseSingleWord(Word);
//		ReverseWord += " ";
//	}
//	return ReverseWord;
//}

//OLD SOLUTION V2

//string ReverseWord(string Word) {
//	string ReverseWord = "";
//	string delim = " ";
//
//	for (int i = Word.length() - 1; i >= 0; i--) {
//		if (Word[i] == ' ') {
//			ReverseWord += Word.substr(i+1);
//			ReverseWord += delim;
//			Word.erase(i);
//		}
//	}
//	if (Word != "") {
//		ReverseWord += Word;
//	}
//	return ReverseWord;
//}


//FINAL SOLUTION

vector <string> SplitString(string word, string delim) {
	int Pos;
	string NewWord;
	vector <string> vec;

	while ((Pos = word.find(delim)) != string::npos) {
		NewWord = word.substr(0, Pos);

		if (NewWord != "") {
			vec.push_back(NewWord);
		}
		word.erase(0, Pos+delim.length());
	}
	if (word != "") {
		vec.push_back(word);
	}
	return vec; 
}

void PrintReverseWord(const vector <string>& vec,string delim) {
	for (int i = vec.size() - 1; i >= 0; i--) {
		cout << vec[i] << delim;
	}
}

string ReverseWordsInString(string word) {
	string ReversedWord = "";
	vector <string> vString = SplitString(word," ");

	vector <string>::iterator itr = vString.end();

	while (itr != vString.begin()) {
		itr--;
		ReversedWord += *itr + " ";
	}
	return ReversedWord;
}

int main()
{
	string Word = "MY NAME IS ABDULRAZAQ AND I AM FROM YEMEN";

	cout << ReverseWordsInString(Word);
}