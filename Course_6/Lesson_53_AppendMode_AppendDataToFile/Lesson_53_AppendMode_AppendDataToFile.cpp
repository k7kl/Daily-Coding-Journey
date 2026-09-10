#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream File;
	string FileName = "TextFile.txt";

	File.open(FileName, ios::app | ios::out); // to append text on the same file without delete the original content or add a new file if there is no file with the same name

	if (File.is_open()) { // to check if the file is already open or not
		File << "\nHello World" << endl;
		File << "My name is Abdulrazaq";
		File.close(); // close the file
	}
	else {
		cout << "the file isn't open";
	}
}