#include <iostream>
#include <iomanip>
using namespace std;

bool CheckIdentityMatrix(int arr[3][3],int Rows,int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (i == j && arr[i][j] != 1) {
				return false;
			}
			else {
				if (arr[i][j] != 0) {
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

void PrintIfIdentityMatrix(bool IsIdentity) {
	if (IsIdentity) {
		cout << "\nYes: Matrix is Identity.\n";
	}
	else {
		cout << "\nNo: Matrix is NOT Identity.\n";
	}
}


int main()
{
	int arr[3][3] = {
		{1,0,0},
		{0,1,0},
		{0,0,1},
	};
	int Rows = 3, Cols = 3;
	PrintMatrix(arr, Rows, Cols);
	PrintIfIdentityMatrix(CheckIdentityMatrix(arr,Rows,Cols));
}