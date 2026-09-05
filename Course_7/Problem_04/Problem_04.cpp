#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumber(int arr[4][4], int Rows,int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			arr[i][j] = RandomNumber(1,100);
		}
	}
}

void PrintMatrix(int arr[4][4], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			cout << setw(4) << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int SumColumns(int arr[4][4],int Rows,int ColsNumber) {
	int Sum = 0;
	for (int i=0; i < Rows; i++) {
		Sum = Sum + arr[i][ColsNumber];
	}
	return Sum;
}

void PrintSumOfColumns(int arr[4][4], int Rows, int Cols) {
	for (int i = 0; i < Cols; i++) {
		cout <<"Column number [" << i+1 <<"] sum is: " << SumColumns(arr, Rows, i)<<endl;
	}
}

int main()
{
	srand(time(0));
	int arr[4][4];
	int Rows = 4;
	int Cols = 4;
	FillMatrixWithRandomNumber(arr,Rows,Cols);
	cout << "\nThe following is a 4x4 Matrix: \n";
	PrintMatrix(arr,Rows,Cols);

	
	PrintSumOfColumns(arr,Rows,Cols);
}