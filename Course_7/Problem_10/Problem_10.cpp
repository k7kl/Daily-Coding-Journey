#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int arr[3][3], int Rows, int Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

int SumMatrixNumber(int arr[3][3], int Rows, int Cols) {
    int TotalSum = 0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            TotalSum += arr[i][j];
        }
    }
    return TotalSum;
}

void PrintMatrix(int arr[3][3], int Rows, int Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            cout << setfill('0')  << setw(2) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(0));
    int arr[3][3];
    int Rows = 3;
    int Cols = 3;

    FillMatrixWithRandomNumbers(arr,Rows,Cols);
    PrintMatrix(arr,Rows,Cols);
    cout << "\nSum of Matrix is: " << SumMatrixNumber(arr,Rows,Cols) << endl;
}