#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string input;
	cout << "Please enter a string?" << endl;
	getline(cin, input);
	return input;
}

string TrimLeft(string word) {
	for (int i = 0; i < word.length(); i++) {
		if (word[i] != ' ') {
			word = word.substr(i,word.length()-i);
			return word;
		}
	}
	return "";
}

string TrimRight(string word) {
	for (int i = word.length()-1; i >= 0; i--) {
		if (word[i] != ' ') {
			word = word.substr(0,i+1);
			return word;
		}
	}
	return "";
}

string Trim(string word) {
	word = TrimLeft(word);
	word = TrimRight(word);
	return word;
}

void PrintResult(string word) {
	cout << "\nThe word is : " << word << " ,Word length: " << word.length() << endl;
	cout << "Trim Left     = " << TrimLeft(word) << " ,Word length: " << TrimLeft(word).length() <<endl;
	cout << "Trim Right    = "<< TrimRight(word) << " ,Word length: " << TrimRight(word).length() << endl;
	cout << "Trim          = " << Trim(word) << " ,Word length: " << Trim(word).length() << endl;
}

int main()
{
	string word = ReadString();
	PrintResult(word);
}