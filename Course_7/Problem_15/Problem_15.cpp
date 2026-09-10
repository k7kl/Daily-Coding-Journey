#include <iostream>
#include <iomanip>
using namespace std;

bool CheckIfSparse(int arr[3][3], int Rows, int Cols) {
    int HalfElementsInMatrix = ((Rows * Cols) / 2) + 1;
    int ZerosCounter = 0;

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (arr[i][j] == 0) {
                ZerosCounter++;
                if (ZerosCounter >= HalfElementsInMatrix) {
                    return true;
                }
            }
        }
    }
    return false;
}

void PrintIfSparseMatrix(bool IsSparseMatrix) {
    if (IsSparseMatrix) {
        cout << "\nYes it's sparse matrix.\n";
    }
    else {
        cout << "\nNo it's NOT sparse matrix.\n";
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
    int arr[3][3] = {
        {1,2,3},
        {1,1,0},
        {0,0,0}
    };
    int Rows =3 , Cols = 3;

    cout << "Matrix1:\n";
    PrintMatrix(arr, Rows, Cols);
    PrintIfSparseMatrix(CheckIfSparse(arr,Rows,Cols));
}