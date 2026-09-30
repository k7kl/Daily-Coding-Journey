#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const string FileName = "Hi.txt";

struct stClientData {
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	double Balance;
};

stClientData ReadClientData() {
	stClientData Client;

	cout << "Enter Account number? ";
	cin >> Client.AccountNumber;
	cout << "Enter Pin Code? ";
	cin >> Client.PinCode;
	cout << "Enter your name? ";
	getline(cin >> ws, Client.Name);
	cout << "Enter your phone number? ";
	cin>> Client.PhoneNumber;
	cout << "Enter your balance? ";
	cin >> Client.Balance;

	return Client;
}

string ConvertClientRecordToLine(stClientData ClientRecord, string delimiter = "##//##") {
	string RecordInLine = "";

	RecordInLine += ClientRecord.AccountNumber + delimiter;
	RecordInLine += ClientRecord.PinCode + delimiter;
	RecordInLine += ClientRecord.Name + delimiter;
	RecordInLine += ClientRecord.PhoneNumber + delimiter;
	RecordInLine += to_string(ClientRecord.Balance);

	return RecordInLine;
}

void AddDataLineToFile(string FileName, string stDataLine) {
	fstream file;
	
	file.open(FileName,ios::out | ios::app);

	if (file.is_open()) {
		file << stDataLine << endl;
		file.close();
	}
	else {
		cout << "\nFile is NOT open.\n";
	}
}

void AddClient() {
	stClientData ClientData;
	bool AddMore = true;
	
	while (AddMore) {
		cout << "Adding New Client:\n\n";
		ClientData = ReadClientData();
		AddDataLineToFile(FileName, ConvertClientRecordToLine(ClientData));
		cout << "\nClient added successfully, if you want to add more more Client press 1 or 0 if NO.";
		cin >> AddMore;
		system("cls");
	}
}

int main()
{
	AddClient();
}