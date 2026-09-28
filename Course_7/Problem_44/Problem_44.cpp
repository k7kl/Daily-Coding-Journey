#include <iostream>
#include <string>
using namespace std;

struct stClientData {
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	float Balance;
};

stClientData ReadClientData() {
	stClientData Client;

	cout << "Enter Account number? ";
	getline(cin,Client.AccountNumber);
	cout << "Enter Pin Code? ";
	getline(cin, Client.PinCode);
	cout << "Enter your name? ";
	getline(cin, Client.Name);
	cout << "Enter your phone number? ";
	getline(cin, Client.PhoneNumber);
	cout << "Enter your balance? ";
	cin >> Client.Balance;

	return Client;
}

string ConvertClientRecordToLine(stClientData ClientRecord,string delimiter = "##//##") {
	string RecordInLine = "";
	
	RecordInLine += ClientRecord.AccountNumber + delimiter;
	RecordInLine += ClientRecord.PinCode + delimiter;
	RecordInLine += ClientRecord.Name + delimiter;
	RecordInLine += ClientRecord.PhoneNumber + delimiter;
	RecordInLine += to_string(ClientRecord.Balance);
	
	return RecordInLine;
}

int main()
{
	stClientData Client = ReadClientData();
	string RecordInLine = ConvertClientRecordToLine(Client);
	cout << "\n\nClient record for saving is: \n";
	cout << RecordInLine;
}