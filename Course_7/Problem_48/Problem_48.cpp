#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

const string FileName = "Hi.txt";

string ReadString() {
	string accountnumber;
	cout << "Please enter an account number?";
	cin >> accountnumber;
	return accountnumber;
}

struct stClientData {
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	double Balance;
};

vector <string> SplitString(string word, string delimiter) {
	int pos;
	string NewWord = "";
	vector <string> vString;

	while ((pos = word.find(delimiter)) != string::npos) {
		NewWord = word.substr(0, pos);

		if (NewWord != "") {
			vString.push_back(NewWord);
		}
		word.erase(0, pos + delimiter.length());
	}
	if (word != "") {
		vString.push_back(word);
	}

	return vString;
}

stClientData ConvertLineToRecord(string line, string delimiter = "##//##") {
	stClientData Client;
	vector <string> vString;
	vString = SplitString(line, delimiter);

	Client.AccountNumber = vString[0];
	Client.PinCode = vString[1];
	Client.Name = vString[2];
	Client.PhoneNumber = vString[3];
	Client.Balance = stod(vString[4]);

	return Client;
}

vector <stClientData> LoadClientDataFromFile(string FileName) {
	fstream file;
	vector <stClientData> ClientData;

	file.open(FileName, ios::in);

	if (file.is_open()) {
		string line = "";

		while (getline(file, line)) {
			ClientData.push_back(ConvertLineToRecord(line));
		}
		file.close();
	}
	else {
		cout << "\nFile is not open!\n";
	}
	return ClientData;
}

void PrintClientRecord(stClientData client) {
	cout << "The Following are the client details:\n\n";
	cout << "Account Number  :" << client.AccountNumber <<endl;

	cout << "Pin Code        :" << client.PinCode << endl;

	cout << "Name            :" << client.Name << endl;

	cout << "Phone Number    :" << client.PhoneNumber << endl;

	cout << "Account Balance :" << client.Balance << endl;

}

bool FindRecordByAccountNumber(const vector <stClientData> &vClients,stClientData &Client2,string AccountNumber) {
	stClientData Client;
	for (const stClientData& client : vClients) {
		if (client.AccountNumber == AccountNumber) {
			Client2 = client;
			return true;
		}
	}
	return false;
}

void PrintIfClientFound(bool IsFound,stClientData Client,string AccountNumber) {
	if (IsFound) {
		PrintClientRecord(Client);
	}
	else {
		cout << "\nClient (" << AccountNumber << ") NOT found!\n";
	}
}

int main()
{
	vector <stClientData> vClients = LoadClientDataFromFile(FileName);
	stClientData Client2;
	string AccountNumber = ReadString();
	bool IsFound= FindRecordByAccountNumber(vClients,Client2, AccountNumber);
	PrintIfClientFound(IsFound, Client2, AccountNumber);
}