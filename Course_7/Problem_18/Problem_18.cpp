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

void PrintMatrix(int arr[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			cout << setfill('0') << setw(2) << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int FindTheMaxNumberInMatrix(int arr[3][3], int Rows, int Cols) {
	int Max = arr[0][0];
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (arr[i][j] > Max) {
				Max = arr[i][j];
			}
		}
	}
	return Max;
}

int FindTheMinNumberInMatrix(int arr[3][3], int Rows, int Cols) {
	int Min = arr[0][0];
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (arr[i][j] < Min) {
				Min = arr[i][j];
			}
		}
	}
	return Min;
}


void PrintMaxNumberInMatrix(int MaxNumber) {
	cout << "The maximum number in the matrix is: " << MaxNumber << endl;
}

void PrintMinNumberInMatrix(int MinNumber) {
	cout << "The minimum number in the matrix is: " << MinNumber << endl;
}

int main()
{
	srand(time(0));
	int arr[3][3];
	int Rows = 3, Cols = 3;

	FillMatrixWithRandomNumber(arr, Rows, Cols);
	PrintMatrix(arr,Rows,Cols);

	PrintMaxNumberInMatrix(FindTheMaxNumberInMatrix(arr,Rows,Cols));
	PrintMinNumberInMatrix(FindTheMinNumberInMatrix(arr,Rows,Cols));
}