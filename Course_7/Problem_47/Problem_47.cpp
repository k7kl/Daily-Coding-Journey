#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct stClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	double balance;
};

vector <string> SplitString(string Line, string delemiter = "#//#") {
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

vector <stClient> LoadClientToVecotr(string FileName) {
	fstream File;
	vector <stClient> vClients;
	File.open(FileName, ios::in);
	string line;
	if (File.is_open()) {
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

void PrintHeadder() {
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

void PrintClientRecord(stClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.PhoneNumber;
	cout << "| " << setw(12) << left << Client.balance;
}

void PrintRecord(vector <stClient> vClients) {
	cout << "\nClient List (" << vClients.size() << ") client(s).\n";
	PrintHeadder();
	for (stClient c : vClients) {
		PrintClientRecord(c);
		cout << endl;
	}
}

int main()
{
	vector <stClient> vClients = LoadClientToVecotr("Hi.txt");
	PrintRecord(vClients);
}