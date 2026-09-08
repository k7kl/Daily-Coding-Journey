#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumber(int arr[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void MultiplayTwoMatrix(int arrA[3][3], int arrB[3][3], int arrResult[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			arrResult[i][j] = arrA[i][j] * arrB[i][j];
		}
	}
}

void PrintMatrix(int arr[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			cout << setfill('0') << setw(2) << arr[i][j] << "  ";
		}
		cout << endl;
	}
}

int main()
{
	srand(time(0));
	int arrA[3][3];
	int arrB[3][3];
	int arrResult[3][3];
	int Rows = 3;
	int Cols = 3;

	FillMatrixWithRandomNumber(arrA, Rows, Cols);
	FillMatrixWithRandomNumber(arrB, Rows, Cols);
	cout << "The matrix one is: \n";
	PrintMatrix(arrA, Rows, Cols); cout << endl;
	cout << "THe matrix two is: \n";
	PrintMatrix(arrB, Rows, Cols);

	cout << "\nThe multiply of 2 matrix is : ";
	MultiplayTwoMatrix(arrA, arrB, arrResult, Rows, Cols);
	cout << endl;
	PrintMatrix(arrResult, Rows, Cols);
}