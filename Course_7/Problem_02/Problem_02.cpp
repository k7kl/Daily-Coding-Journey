#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumber(int arr[3][3],int Rows,int Cols) {
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

int RowSum(int arr[3][3], int Cols,int RowNumber) {
	int total=0;

	for (int j = 0; j < Cols; j++) {
		total = total + arr[RowNumber][j];
	}
	return total;
}


void PrintEachRowSum(int arr[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		cout << "Row "<<i+1 << " Sum = " << setw(3) << RowSum(arr, Cols, i);
		cout << endl;
	}
}

int main()
{
	srand(time(0));
	int arr[3][3];
	int Rows = 3;
	int Cols = 3;

	FillMatrixWithRandomNumber(arr, Rows, Cols);
	cout << "\nThe following is 3x3 random matrix: " << endl;
	PrintMatrix(arr, Rows, Cols);
	cout << "\nThe following are the sum of each row: \n";
	PrintEachRowSum(arr,Rows,Cols);
}