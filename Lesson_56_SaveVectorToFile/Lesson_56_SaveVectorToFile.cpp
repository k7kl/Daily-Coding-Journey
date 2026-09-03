#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void SaveVectorToFile(const string& FileName, vector <string>& vNames) {
    fstream File;
    File.open(FileName, ios::out);

    if (File.is_open()) {
        for (const string& name : vNames) {
            File << name << endl;
        }
        File.close();
    }
    else {
        cout << "File isn't open";
    }
}

int main()
{
    vector <string> vNames{ "Ahmed" , "Omer" , "Khaled" , "Mohmmaed" , "Abdulrazaq" };
    string FileName = "Names.txt";

    SaveVectorToFile(FileName,vNames);
}