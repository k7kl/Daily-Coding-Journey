#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const string FileName = "Hi.txt";

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
	vString = SplitString(line,delimiter);

	Client.AccountNumber =vString[0];
	Client.PinCode		 =vString[1];
	Client.Name			 =vString[2];
	Client.PhoneNumber	 =vString[3];
	Client.Balance		 = stod(vString[4]);

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
	return ClientData;
}

void PrintHeader(int NumberOfClients) {
	cout << setfill(' ') << setw(52) << "Client List (" << NumberOfClients << ") Client(s).\n";

	cout << setfill('_') << setw(104) << "" << endl << endl;
	cout << "|" << setw(20) << left << setfill(' ') << "Account Number";
	cout << "|" << setw(11) << left << "Pin Code";
	cout << "|" << setw(45) << left << "Client Name";

	cout << "|" << setw(15) << "Phone";
	cout << "|" << setw(7) << "Balance";

	cout << endl << setfill('_') << setw(104) << "" << endl;
}

void PrintClientRecord(stClientData client) {
	cout << "|" << setw(20) << left << setfill(' ') << client.AccountNumber;

	cout << "|" << setw(11) << client.PinCode;

	cout << "|" << setw(45) << client.Name;

	cout << "|" << setw(15) << client.PhoneNumber;

	cout << "|" << setw(7) << client.Balance << "| " << endl;

}

void PrintAllClientRecord(vector <stClientData> vClients) {
	PrintHeader(vClients.size());
	for (const stClientData& client : vClients) {
		PrintClientRecord(client);
	}
	
    cout << setfill('_') << setw(104) << "" << endl;
}

int main()
{
	PrintAllClientRecord(LoadClientDataFromFile(FileName));
}