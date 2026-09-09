#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumber(int arr[3][3],int Rows,int Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

bool CheckIfMatrixEquivalent(int arr[3][3],int arr2[3][3], int Rows, int Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (arr[i][j] != arr2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void PrintIfMatrixEquivalent(bool IsEquivalent) {
    if (IsEquivalent) {
        cout << "\nYES: both matrices are equal.\n";
    }
    else {
        cout << "\nNo: matrices are NOT equal.\n";
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
    int Rows = 3, Cols=3;
    FillMatrixWithRandomNumber(arr,Rows,Cols);
    FillMatrixWithRandomNumber(arr2,Rows,Cols);
    cout << "\nMatrix1:\n";
    PrintMatrix(arr, Rows, Cols);
    cout << "\nMatrix2:\n";
    PrintMatrix(arr2,Rows,Cols);
    PrintIfMatrixEquivalent(CheckIfMatrixEquivalent(arr, arr2, Rows, Cols));
}