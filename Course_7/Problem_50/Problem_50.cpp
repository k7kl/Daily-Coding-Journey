#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
const string FileName = "Hi.txt";

struct stClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	double balance;
	bool isDeleted = false;
};

string ReadAccountNumber() {
	string accountnumber;
	cout << "Please enter the account number? ";
	cin >> accountnumber;
	return accountnumber;
}

vector <string> SplitString(string Line, string delemiter = "##//##") {
	string NewWord = "";
	int pos = 0;
	vector <string> vClientData;

	while ((pos = Line.find(delemiter)) != string::npos) {
		NewWord = Line.substr(0, pos);

		if (NewWord != "") {
			vClientData.push_back(NewWord);
		}
		Line.erase(0, pos + delemiter.length());
	}
	if (Line != "")
		vClientData.push_back(Line);
	return vClientData;
}

stClient ConvertLineToClient(string Line, string delemiter = "##//##") {
	stClient c;
	vector <string> vClientData = SplitString(Line, delemiter);
	c.AccountNumber = vClientData[0];
	c.PinCode = vClientData[1];
	c.Name = vClientData[2];
	c.PhoneNumber = vClientData[3];
	c.balance = stod(vClientData[4]);
	return c;
}

vector <stClient> LoadClientToVecotrFromFile(string FileName) {
	fstream File;
	vector <stClient> vClients;

	File.open(FileName, ios::in);

	if (File.is_open()) {
		string line;
		while (getline(File, line)) {
			stClient c = ConvertLineToClient(line);
			vClients.push_back(c);
		}
		File.close();
	}
	else {
		cout << "\nfile is not open\n";
	}
	return vClients;
}

void ReadClientData(stClient &Client) {

	cout << "Enter Pin Code? ";
	cin >> Client.PinCode;
	cout << "Enter your name? ";
	getline(cin >> ws, Client.Name);
	cout << "Enter your phone number? ";
	cin >> Client.PhoneNumber;
	cout << "Enter your balance? ";
	cin >> Client.balance;
}

void EditClientData(vector <stClient>& vClients, const string& AccountNumber) {
	for (stClient& c : vClients) {
		if (AccountNumber == c.AccountNumber) {
			ReadClientData(c);
			break;
		}
	}
}

string ConvertRecordToLine(const stClient& c, string delemiter = "##//##") {
	string Line = "";
	Line += c.AccountNumber + delemiter;
	Line += c.PinCode + delemiter;
	Line += c.Name + delemiter;
	Line += c.PhoneNumber + delemiter;
	Line += to_string(c.balance);
	return Line;
}

void SaveVectorToFile(const vector <stClient>& vClientsData, string FileName, const string& delemiter = "##//##") {
	fstream File;
	File.open(FileName, ios::out);

	if (File.is_open()) {
		for (const stClient& c : vClientsData) {
			if (c.isDeleted != true) {
				string Line = ConvertRecordToLine(c);
				File << Line << endl;
			}
		}
		File.close();
	}
	else {
		cout << "\nFile is close!\n";
	}
}

void PrintClientDetails(const stClient& c) {
	cout << "\nThe following are the client details:";
	cout << "\nAccount Number: " << c.AccountNumber << endl;
	cout << "Name          : " << c.Name << endl;
	cout << "Phone Number  : " << c.PhoneNumber << endl;
	cout << "Pin Code      : " << c.PinCode << endl;
	cout << "Balance       : " << c.balance << endl;
}

bool FindClientByAccountNumber(const vector <stClient>& vClients, const string& AccountNumber, stClient& Client) {
	for (const stClient& c : vClients) {
		if (c.AccountNumber == AccountNumber) {
			Client = c;
			return true;
		}
	}
	return false;
}

void EditClient(vector <stClient>& vClientsData, const string& AccountNumber) {
	stClient Client;
	bool isFound = FindClientByAccountNumber(vClientsData, AccountNumber, Client);
	char Answer = 'n';


	if (isFound) {
		PrintClientDetails(Client);
		cout << "Are you sure you want to edit this client? y/n ?";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {
			EditClientData(vClientsData, AccountNumber);
			SaveVectorToFile(vClientsData, FileName);
			cout << "\nClient is edited successfully!\n";
		}
	}
	else {
		cout << "\nClient is NOT found!\n";
	}
}

int main()
{
	vector <stClient> vClientsData = LoadClientToVecotrFromFile(FileName);
	string AccountNumber = ReadAccountNumber();
	EditClient(vClientsData, AccountNumber);
}