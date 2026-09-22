#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString() {
	string input;
	cout << "Please enter your string?" << endl;
	getline(cin, input);
	return input;	
}

string ReadDelimiter() {
	string input;
	cout << "Please enter your Delimiter?";
	getline(cin, input);
	return input;
}

vector <string> SplitString(string word,string Delim) {
	int Pos;
	string NewWord;
	vector <string> myVector;

	while ((Pos = word.find(Delim)) != string::npos) {
		NewWord = word.substr(0, Pos);
		if (NewWord != "")
			myVector.push_back(NewWord);
		word.erase(0, Pos + Delim.length());
	}
	if (word != "")
		myVector.push_back(word);
	return myVector;
}

void PrintVector(vector <string>& myVector) {

	for (const string& Vec : myVector) {
		cout << Vec << endl;
	}
}

int main()
{
	string word = ReadString();
	string Delim = ReadDelimiter();
	vector <string> myVector = SplitString(word, Delim);
	cout << "Tokens = " << myVector.size() << endl;
	PrintVector(myVector);
}