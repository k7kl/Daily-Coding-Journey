#include <iostream>
#include <iomanip>
using namespace std;

void PrintMatrix(int Matrix1[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			cout << setfill('0') << setw(2) << Matrix1[i][j] << " ";
		}
		cout << endl;
	}A
}

bool IsMatrixPalindrome(int Matrix1[3][3], int Rows,int Cols ) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols / 2; j++) {
			if (Matrix1[i][j] != Matrix1[i][Cols - 1 - j]) {
				return false;
			}
		}
	}
	return true;
}

void PrintIfMatrixIsPalindrome(bool IsPalindrome) {
	if (IsPalindrome) {
		cout << "\nYes: Matrix is palindrome.\n";
	}
	else {
		cout << "\nNo: Matrix is NOT palindrome.\n";
	}
}

int main()
{
	int Matrix1[3][3] = { 
		{1,2,1},
		{5,5,5},
		{12,1,12} 
	};
	int Rows = 3, Cols = 3;
	cout << "\nMatrix1\n";
	PrintMatrix(Matrix1,Rows,Cols);
	PrintIfMatrixIsPalindrome(IsMatrixPalindrome(Matrix1,Rows,Cols));
}