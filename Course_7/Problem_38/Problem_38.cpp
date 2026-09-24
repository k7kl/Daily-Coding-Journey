#include <iostream>
#include <vector>
using namespace std;

string JoinString(const vector <string>& vNames,string delim) {
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

int main()
{
	vector <string> vNames = { "Ahmed","Omer","Amro","Khaled","Saud","Dahommy","Nawaf" };
	string word = JoinString(vNames,",");
	cout << "\nVector after join: \n\n";
	cout << word;
}