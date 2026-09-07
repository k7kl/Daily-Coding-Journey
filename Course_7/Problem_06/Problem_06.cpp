#include <iostream>
#include <iomanip>
using namespace std;

void FillMatrixWithOrderNumber(int arr[3][3], int Rows,int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			arr[i][j] = (i*Cols) +j+1;
		}
	}	
}

void PrintMatrix(int arr[3][3], int Rows, int Cols) {
	for (int i=0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			cout <<setw(3) << arr[i][j] ;
		}
		cout << endl;
	}
}

int main()
{
	int Rows = 3;
	int Cols = 3;
	int arr[3][3];
	FillMatrixWithOrderNumber(arr,Rows,Cols);
	cout << "\nThe following is an 3x3 order matrix: \n";
	PrintMatrix(arr, Rows, Cols);
}