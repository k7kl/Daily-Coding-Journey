#include <iostream>
#include <string>
#include <vector>
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

	Client.Name = vNames[RandomNumber(0, vNames.size()-1)];
	Client.Balance = RandomNumber(1000, 5000);
	Client.AccountNumber = to_string(RandomNumber(100, 999));
	Client.PhoneNumber = vPhoneNumbers[RandomNumber(0, vPhoneNumbers.size()-1)];
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

vector <string> SplitString(string Word,string Delimiter) {
	vector <string> vString;
	int pos;
	string NewWord="";

	while ((pos = Word.find(Delimiter)) != string::npos) {
		NewWord = Word.substr(0,pos);

		if (NewWord != "")
			vString.push_back(NewWord);

		Word.erase(0,pos+Delimiter.length());
	}
	if (Word != "") {
		vString.push_back(Word);
	}
	return vString;
}

stClientData ConvertLineToRecord(string Line,string delimiter) {
	stClientData Client;
	vector <string> vString = SplitString(Line,delimiter);
	
	Client.AccountNumber =  vString[0];
	Client.PinCode = vString[1];
	Client.Name = vString[2];
	Client.PhoneNumber = vString[3];
	Client.Balance = stod(vString[4]);

	return Client;
}

void PrintClientRecord(stClientData Client) {
	cout << "Account number : " << Client.AccountNumber << endl;
	cout << "Pin Code       : " << Client.PinCode << endl;
	cout << "Name           : " << Client.Name << endl;
	cout << "Phone          : " << Client.PhoneNumber << endl;
	cout << "Account Balance: " << Client.Balance << endl;
}

int main()
{
	srand(time(0));
	stClientData Client = FillRecordWithRandom();
	string RecordInLine = ConvertClientRecordToLine(Client);
	cout << "\nLine Record is: \n";
	cout << RecordInLine;
	cout << "\n\nThe following is the extracted client record:\n\n";
	PrintClientRecord(ConvertLineToRecord(RecordInLine, "##//##"));
}