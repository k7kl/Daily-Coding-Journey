#include <iostream>
#include <vector>
using namespace std;

string JoinString(const vector <string>& vNames, string delim) {
	string word = "";
	if (vNames.size() > 0) {
		word += vNames[0];
	}

	for (int i = 1; i < vNames.size(); i++) {
		word += delim;
		word += vNames[i];
	}
	return word;
}

string JoinString(string arr[],int ArrSize, string delim) {
	string word = "";
	if (ArrSize > 0) {
		word += arr[0];
	}

	for (int i = 1; i < ArrSize; i++) {
		word += delim;
		word += arr[i];
	}
	return word;
}

int main()
{
	vector <string> vNames = { "Ahmed","Omer","Amro","Khaled","Saud","Dahommy","Nawaf" };
	int ArrSize = 7;
	string arr[7] = {"Ahmed","Omer","Amro","Khaled","Saud","Dahommy","Nawaf"};

	string word = JoinString(arr,ArrSize, ",");
	cout << "\nArray after join: \n\n";
	cout << word;
}