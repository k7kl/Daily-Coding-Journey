#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void LoadDataFromFileToVector(string &FileName,vector <string>& vNames) {
	fstream File;

	File.open(FileName, ios::in);

	if (File.is_open()) {
		string Line;

		while (getline(File, Line)) {
			if (Line != "") {
				vNames.push_back(Line);
			}
		}
		File.close();
	}
	else {
		cout << "File isn't open";
	}
}


int main()
{
	vector <string> vNames;
	string FileName = "Test.txt";

	LoadDataFromFileToVector(FileName, vNames);
	//print vector elements
	for (const string& name : vNames) {
		cout << name << endl;
	}
}