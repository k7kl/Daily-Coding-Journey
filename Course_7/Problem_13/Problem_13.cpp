#include <iostream>
#include <iomanip>
using namespace std;

bool CheckIfScalarMatrix(int arr[3][3], int Rows, int Cols) {
	int Scalar = arr[0][0];
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (i == j && arr[i][j] != Scalar) {
				return false;
			}
			else {
				if (i != j && arr[i][j] != 0) {
					return false;
				}
			}
		}
	}
	return true;
}

void PrintMatrix(int arr[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			cout << setfill('0') << setw(2) << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void PrintIfScalarMatrix(bool IsScalarMatrix) {
	if (IsScalarMatrix) {
		cout << "\nYes: Matrix is Scalar matrix.\n";
	}
	else {
		cout << "\nNo: Matrix is NOT Scalar matrix.\n";
	}
}


int main()
{
	int arr[3][3] = {
		{10,0,0},
		{0,10,0},
		{0,0,10},
	};
	int Rows = 3, Cols = 3;
	PrintMatrix(arr, Rows, Cols);
	PrintIfScalarMatrix(CheckIfScalarMatrix(arr, Rows, Cols));
}