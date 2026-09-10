#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void LoadDataFromFileToVector(string& FileName, vector <string>& vNames) {
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

void SaveVectorToFile(const string& FileName, vector <string>& vNames) {
	fstream File;
	File.open(FileName, ios::out);

	if (File.is_open()) {
		for (const string& name : vNames) {
			if (name != "") {
				File << name << endl;
			}
		}
		File.close();
	}
	else {
		cout << "File isn't open";
	}
}

void UpdateRecordInFile(string FileName,string Record, string NewValue) {
	vector <string> vNames;
	LoadDataFromFileToVector(FileName,vNames);

	for (string& name : vNames) {
		if (name == Record) {
			name = NewValue;
		}
	}
	SaveVectorToFile(FileName,vNames);
}

int main()
{
	string FileName = "Names.txt";
	UpdateRecordInFile(FileName,"Ahmed","xxxxxxxxxxxxxx");
}