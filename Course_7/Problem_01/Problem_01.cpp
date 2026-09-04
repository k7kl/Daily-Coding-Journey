#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void GenerateRandomNumberToMatrix(int arr[3][3],int Rows,int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			arr[i][j] = RandomNumber(1,99);
		}
	}
}

void PrintMatrix(int arr[3][3],int Rows,int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			cout  << setw(3) << arr[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{
	srand(time(0));
	int arr[3][3];

	cout << "\nThe following is a 3x3 matrix with random number: " << endl;
	GenerateRandomNumberToMatrix(arr,3,3);
	PrintMatrix(arr,3,3);
}