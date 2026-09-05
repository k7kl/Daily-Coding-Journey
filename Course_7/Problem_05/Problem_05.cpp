#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}
}

int SumColumn(int arr[3][3], short Rows, short ColNumber) {
	int sum = 0;
	for (short i = 0; i < Rows; i++) {
		sum = sum + arr[i][ColNumber];
	}
	return sum;
}

void SaveSumOfColumnOnArray(int arr[3][3], int arr2[3], short Rows, short size) {
	for (int i = 0; i < size; i++) {
		arr2[i] = SumColumn(arr, Rows, i);
	}
}

void PrintArray(int arr2[3], short size) {
	for (int i = 0; i < size; i++) {
		cout << " Col " << i + 1 << " Sum = " << arr2[i] << endl;
	}
}

int main()
{
	srand(time(0));
	int arr[3][3];
	int arr2[3];
	short Rows = 3;
	short Cols = 3;
	FillMatrixWithRandomNumber(arr, Rows, Cols);
	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(arr, Rows, Cols);
	SaveSumOfColumnOnArray(arr, arr2, Rows, 3);
	cout << "\nThe following are the sum of each col in the matrix:\n";
	PrintArray(arr2, 3);
}