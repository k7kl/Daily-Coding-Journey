#pragma once
#include <iostream>
using namespace std;

namespace InputLib {

	int ReadPositiveNumber(string message) {
		int number=0;
		do {
			cout << message << " ";
			cin >> number;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				cout << "Invalid number, Enter a valid number: " << endl;
				cin >> number;
			}
		} while (number < 0);
		return number;
	}

	int ReadNumber(string message) {
		int number=0;
		cout << message << " ";
		cin >> number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Invalid number, Enter a valid number: " << endl;
			cin >> number;
		}
		return number;
	}
}

