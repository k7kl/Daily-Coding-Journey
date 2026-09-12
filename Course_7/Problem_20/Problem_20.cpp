#include <iostream>
#include <iomanip>
using namespace std;

void PrintFibonacciSeriesUsingLoop(int Number) {
	int Feb3;
	int Feb1 = 1;
	int Feb2 = 1;
	cout << "1\t1\t";
	for (int i = 0; i < Number -2; i++) {
		Feb3 = Feb1 + Feb2;
		cout << Feb3 << "\t";
		Feb1 = Feb2;
		Feb2 = Feb3;
	}
}

int main()
{
	PrintFibonacciSeriesUsingLoop(10);
}