#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumber(int arr[3][3],int Rows,int Cols)
{
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			arr[i][j] = RandomNumber(1,100);
		}
	}
}

bool IsNumberInMatrix(int arr2[3][3], int Rows, int Cols,int Number) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (Number == arr2[i][j]) {
				return true;
			}
		}
	}
	return false;
}

void PrintIntersectedNumbers(int arr[3][3],int arr2[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (IsNumberInMatrix(arr2, Rows, Cols, arr[i][j])) {
				cout << arr[i][j] << "  ";
			}
		}
	}
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
	srand(time(0));
	int arr[3][3], arr2[3][3];
	int Rows = 3, Cols = 3;
	FillArrayWithRandomNumber(arr,Rows,Cols);
	FillArrayWithRandomNumber(arr2,Rows,Cols);

	cout << "\nMatrix 1: \n";
	PrintMatrix(arr, Rows, Cols);
	cout << "\nMatrix 2: \n";
	PrintMatrix(arr2, Rows, Cols);

	cout << "\nIntersected Numbers are: \n";
	PrintIntersectedNumbers(arr, arr2, Rows, Cols);
}