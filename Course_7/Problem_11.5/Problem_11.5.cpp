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
            cout << setfill('0') << setw(2) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool CheckSumEquilty(int arr[3][3], int arr2[3][3], int Rows, int Cols) {
    return (SumMatrixNumber(arr, Rows, Cols) == SumMatrixNumber(arr2, Rows, Cols));
}

void PrintIfEquivalent(bool IsEquivalent) {
    if (IsEquivalent) {
        cout << "\nYES: both matrices are equal.";
    }
    else {
        cout << "\nNo: matrices are NOT equal.";
    }
}

int main()
{
    srand(time(0));
    int arr[3][3];
    int arr2[3][3];
    int Rows = 3;
    int Cols = 3;

    FillMatrixWithRandomNumbers(arr, Rows, Cols);
    FillMatrixWithRandomNumbers(arr2, Rows, Cols);
    cout << "\nMatrix 1:\n";
    PrintMatrix(arr, Rows, Cols);
    cout << "\nMatrix 2:\n";
    PrintMatrix(arr2, Rows, Cols);
    cout << "\nSum of Matrix 1 is: " << SumMatrixNumber(arr, Rows, Cols) << endl;
    cout << "\nSum of Matrix 2 is: " << SumMatrixNumber(arr2, Rows, Cols) << endl;
    PrintIfEquivalent(CheckSumEquilty(arr, arr2, Rows, Cols));

}