#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumber(int arr[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			arr[i][j] = RandomNumber(1,10);
		}
	}
}

bool CheckInNumberExistInMatrix(int arr[3][3], int Rows, int Cols,int Number) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (Number == arr[i][j]) {
				return true;
			}
		}
	}
	return false;
}

void PrintIfNumberExistInMatrix(bool IsExist, int Number) {
	if (IsExist) {
		cout << "\nNumber " << Number << " exist in matrix.\n";
	}
	else {
		cout << "\nNumber " << Number << " NOT exist in matrix.\n";
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
	int arr[3][3];
	int Rows = 3, Cols = 3;
	int Number;

	FillMatrixWithRandomNumber(arr, Rows, Cols);
	
	PrintMatrix(arr, Rows, Cols);
	cout << endl;

	cout << "Please enter a number: ";
	cin >> Number;
	PrintIfNumberExistInMatrix(CheckInNumberExistInMatrix(arr, Rows, Cols, Number),Number);
}