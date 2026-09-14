#include <iostream>
#include <iomanip>
using namespace std;

void PrintFibonacciUsingRecursion(int runTimes,int Number1,int Number2) {
	int total = Number1 + Number2;

	if (0 >= runTimes) {
		return;
	}
	cout << total << "\t";

	PrintFibonacciUsingRecursion(runTimes - 1 ,Number2,total);
}

int main()
{
	PrintFibonacciUsingRecursion(10,1,0);
}