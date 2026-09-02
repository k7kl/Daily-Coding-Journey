#include<iostream>
#include<iomanip>
#include "InputLib.h";
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
using namespace InputLib;
using namespace std;


//string isPositive() {
//	int number = ReadNumber("Please enter a number");
//
//	return number == 0 ? "Zero" : number > 0 ? "Positive" : "negative";
//}
//int MySum(int a, int b, int c = 0, int d = 0) {
//	return (a + b + c + d);
//}
//
//
//
//int Pow(int number,int Power) {
//	if (Power == 0)
//		return 1;
//	return (number * Pow(number, Power-1));
//}

//////////////////////////////////////////////////////////////

//void calculteMultTable(int arr[10][10]) {
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 10; j++) {
//			arr[i][j] = (i+1) * (j+1);
//		}
//	}
//}
//
//void PrintMultiTable(int arr[10][10]) {
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 10; j++) {
//			//cout << arr[i][j] << " ";
//			printf("%0*d ", 2, arr[i][j]);
//		}
//		cout << endl;
//	}
//}

//////////////////////////////////////////////////////////////

//void ReadVector(vector <int>& vNumbers) {
//	char AnotherNumber = 'y' ;
//	int number = 0;
//	do {
//		cout << "Please enter a number to the vector: " << endl;
//		cin >> number;
//		while (cin.fail()) {
//			cin.clear();
//			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			cout << "Invalid number, Enter a valid number: " << endl;
//			cin >> number;
//		}
//		vNumbers.push_back(number);
//		cout << "Do you want to add another number? y/n"<< endl;
//		cin >> AnotherNumber;
//	} while (AnotherNumber == 'y' || AnotherNumber == 'Y');
//}
//
//void printVctorNumbers(vector <int>& vNumbers) {
//	cout << "Vector elements:  \n\n";
//	for (const int &number : vNumbers) {
//		cout << number << " ";
//	}
//}

//struct Employee {
//	string name;
//	string addrass;
//	string phoneNumber;
//	int age;
//};
//
//void ReadEmployeeInformation(vector <Employee>& vEmployee) {
//	Employee TempEmployee;
//	int age = 0;
//	short MinAge = 18;
//	short MaxAge = 50;
//	char AnotherEmployee = 'y';
//
//
//	do {
//		cout << "\nPlease enter employee name: ";
//		cin >> TempEmployee.name; cout << endl;
//		printf("Please enter employee age between %d and %d: ", MinAge, MaxAge);
//		TempEmployee.age = ReadNumber((""));
//		while (TempEmployee.age < 18 || TempEmployee.age > 50) {
//			printf("Please enter employee age between %d and %d: ", MinAge, MaxAge);
//			TempEmployee.age = ReadNumber((""));
//		}
//
//		cout << "please enter employee address: ";
//		cin >> TempEmployee.addrass;
//
//		cout << "Please enter employee number:";
//		cin >> TempEmployee.phoneNumber;
//
//		vEmployee.push_back(TempEmployee);
//
//		cout << "Do you want to add another employee? Y/N: ";
//		cin >> AnotherEmployee;
//	} while (AnotherEmployee == 'y' || AnotherEmployee == 'Y');
//}
//
//void PrintEmployeesInformation(vector <Employee>& vEmployee) {
//	for (Employee& emp : vEmployee) {
//		printf("Employee name is %s.\n",emp.name.c_str());
//		printf("Employee age is %d.\n",emp.age);
//		printf("Employee phone number is %s.\n",emp.phoneNumber.c_str());
//		printf("Employee address is %s.\n",emp.addrass.c_str());
//	}
//}
//
//void changeValue(int &a) {
//	a = 2;
//}

//void swap(int *x, int *y) {
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}

//////////////////////////////////////////////////////////////

void PrintTxtFile(string FileName) {
	fstream File;

	File.open(FileName, ios::in);

	if (File.is_open()) {
		string Line;

		while (getline(File, Line)) {
			if (Line != "") {
				cout << Line << endl;
			}
		}
		File.close();
	}
	else {
		cout << "The file isn't open";
	}
}


void PrintVectorElements(vector <string>& vNames) {
	for (vector <string>::iterator itr = vNames.begin(); itr != vNames.end(); itr++) {
		cout << *itr << endl;
	}
}

void SaveVectorToFile(string FileName,vector <string>& vNames) {
	fstream File;

	File.open(FileName , ios::out);

	if (File.is_open()) {
		for (vector <string>::iterator itr = vNames.begin(); itr != vNames.end(); itr++) {
			if (*itr != "")
				File << *itr << endl;
		}
		cout << "File " << FileName << " is created successfully" << endl;
	}
	else {
		cout << "File isn't open";
	}
}

void LoadFileToVector(string FileName, vector <string>& vNames) {
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
		cout << "File isn't open.";
	}
}

void DeleteRecordForFile(string FileName,string DelLine) {
	vector <string> newVector;
	LoadFileToVector(FileName, newVector);
	for (vector <string>::iterator itr = newVector.begin(); itr != newVector.end(); itr++) {
		if (*itr == DelLine) {
			*itr = "";
		}
	}
	SaveVectorToFile(FileName, newVector);
}


int main() 
{

	string FileName = "D:\\Q8.txt";

	DeleteRecordForFile(FileName, "Saud");

	PrintTxtFile(FileName);

	return 0;
}



