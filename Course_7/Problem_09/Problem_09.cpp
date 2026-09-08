#include <iostream>
#include <iomanip>
#include <cmath>
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

void PrintMatrix(int arr[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
}

void PrintRowOfMatrix(int arr[3][3], int Cols, int RowNumber) {
	cout << "\nThe following is the Row " << RowNumber << " of the matrix: \n";
	for (int j = 0; j < Cols; j++) {
		cout << setw(3) << arr[RowNumber - 1][j];
	}
}

void PrintColOfMatrix(int arr[3][3], int Rows, int ColNumber) {
	cout << "\nThe following is the Column " << ColNumber << " of the matrix: \n";
	for (int i = 0; i < Rows; i++) {
		cout << setw(3) << arr[i][ColNumber - 1];
	}
}


int main()
{
	srand(time(0));
	int arr[3][3];
	int Rows = 3;
	int Cols = 3;

	FillMatrixWithRandomNumber(arr, Rows, Cols);
	PrintMatrix(arr, Rows, Cols);
	PrintRowOfMatrix(arr, Cols,  ceil((float)Rows /2));
	PrintColOfMatrix(arr, Rows, ceil((float)Cols / 2));
}