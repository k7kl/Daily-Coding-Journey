#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumber(int arr[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}
}

int RowSum(int arr[3][3], int Cols, int RowNumber) {
	int total = 0;

	for (int j = 0; j < Cols; j++) {
		total = total + arr[RowNumber][j];
	}
	return total;
}

void CalculateRowsSum(int arr[3][3], int arr2[3] , int arr1Rows, int arr1Cols) {
	for (int i = 0; i < arr1Rows; i++) {
		arr2[i] = RowSum(arr, arr1Cols, i);
	}
}

void PrintArray(int arr[3], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Row " << i + 1 << " Sum = " << setw(4) << arr[i] << endl;
	}
}

int main()
{
	srand(time(0));
	int arr[3][3];
	int arr2[3];
	int arr1Rows = 3;
	int arr1Cols = 3;

	FillMatrixWithRandomNumber(arr, arr1Rows, arr1Cols);
	cout << "\nThe following is 3x3 random matrix:\n";
	PrintMatrix(arr, arr1Rows, arr1Cols);

	CalculateRowsSum(arr, arr2 , arr1Rows,arr1Cols);
	cout << endl;
	cout << "\nThe following are the sum of each row in the matrix:\n";
	PrintArray(arr2, 3);
}