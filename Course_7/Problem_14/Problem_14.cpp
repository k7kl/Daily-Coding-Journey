#include <iostream>
#include <iomanip>
using namespace std;

int CountNumberInMatrix(int arr[3][3], int Rows, int Cols, int Number) {
	int Counter=0;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (arr[i][j] == Number) {
				Counter++;
			}
		}
	}
	return Counter;
}

void PrintMatrix(int arr[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			cout << setfill('0') << setw(2) << arr[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{
	int arr[3][3] = {
		{1,2,3},
		{1,3,1},
		{1,2,1}
	};
	int Rows = 3, Cols = 3;
	int Number;

	cout << "Please enter a number to count it? " << endl;
	cin >> Number;
	cout << "Matrix 1 \n";
	PrintMatrix(arr,Rows,Cols);
	cout << "\nNumber " << Number << " count in matrix is " << CountNumberInMatrix(arr,Rows,Cols,Number);
}