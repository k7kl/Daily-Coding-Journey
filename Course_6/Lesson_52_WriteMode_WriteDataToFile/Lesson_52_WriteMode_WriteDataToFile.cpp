#include <iostream>
#include <fstream> // To use File system
using namespace std;




int main()
{
	fstream File; // Variable fstream type
	string FileName = "MyFirstFile.txt";


	File.open(FileName, ios::out); //ios::out to give a permission to write on the file

	if (File.is_open()) {
		File << "Hello world this is my first file!\n";
		File << "My name is Abdulrazaq Saleh";
		File.close(); //close the file after opening
	}
	else {
		cout << "The file isn't open!";
	}
}
