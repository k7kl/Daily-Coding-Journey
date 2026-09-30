#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct stClientData {
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	double Balance;
};

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

stClientData FillRecordWithRandom() {
	stClientData Client;
	vector <string> vNames = { "Ahmed","Khaled","Omer","Maher","Mohammed","Ali","Saleh","Abdulrazaq" };
	vector <string> vPhoneNumbers = { "737667033","2324253533","34534534534","3453453543","867442523235" };

	Client.Name = vNames[RandomNumber(0, vNames.size() - 1)];
	Client.Balance = RandomNumber(1000, 5000);
	Client.AccountNumber = to_string(RandomNumber(100, 999));
	Client.PhoneNumber = vPhoneNumbers[RandomNumber(0, vPhoneNumbers.size() - 1)];
	Client.PinCode = to_string(RandomNumber(1000, 9000));
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



void SaveClientToFile(string FileName, stClientData ClientData) {
	fstream file;
	string record = ConvertClientRecordToLine(ClientData);

	file.open(FileName, ios::out | ios::app);

	if (file.is_open()) {
		file << record << endl;
		file.close();
	}
	else {
		cout << "\nFile is NOT open.\n";
	}
}


int main()
{
	srand(time(0));

	bool AddMore = true;
	int HowManyRecord = 0;
	cout << "How many random record do you want to add??";
	cin >> HowManyRecord;

	while (0 < HowManyRecord) {
		stClientData ClientData = FillRecordWithRandom();
		SaveClientToFile("Hi.txt", ClientData);
		HowManyRecord--;
	}
	cout << "\nClients added successfully\n";
}