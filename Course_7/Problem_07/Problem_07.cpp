#include <iostream>
#include <iomanip>
using namespace std;

void FillMatrixWithOrderNumber(int arr[4][4], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			arr[i][j] = (i * Cols) + j + 1;
		}
	}
}

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void TransposeMatrix(int arr[4][4],int Rows,int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = i; j < Cols; j++) {
			Swap(arr[i][j], arr[j][i]);
		}
	}
}

void PrintMatrix(int arr[4][4] , int Rows,int Cols) {
	for (int i = 0; i < Rows ; i++) {
		for (int j = 0; j < Cols; j++) {
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
}

int main()
{
	int arr[4][4];
	int Rows = 4;
	int Cols = 4;
	FillMatrixWithOrderNumber(arr,Rows,Cols);
	cout << "\nThe following is a 4x4 ordered matrix: \n";
	PrintMatrix(arr, Rows, Cols);
	TransposeMatrix(arr,Rows,Cols);
	cout << "\nThe following is the transposed matrix: \n";
	PrintMatrix(arr,Rows,Cols);
}