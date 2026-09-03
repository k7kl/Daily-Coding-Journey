#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream File;
    string FileName = "Test.txt";
    File.open(FileName, ios::in);

    if (File.is_open()) {
        string Line;

        while (getline(File, Line)) {
            cout << Line << endl;
        }
        File.close();
    }
    else {
        cout << "File isn't open\n";
    }
}