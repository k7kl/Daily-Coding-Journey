#include <iostream>
using namespace std;

char ReadChar() {
	char Letter;
	cout << "Please Enter a Letter?\n";
	cin >> Letter;
	return Letter;
}

bool IsVowel(char Letter) {
	Letter = tolower(Letter);

	switch (Letter) {
	case 'a': case 'e': case 'i': case 'o': case 'u':
		return true;
	default:
		return false;
	}
}

void DisplayVowelCheckResult(bool IsVowel,char Letter) {
	if (IsVowel) {
		cout << "Yes Letter '" << Letter << "' is vowel";
	}
	else {
		cout << "NO Letter '" << Letter << "' is NOT vowel";
	}
}

int main()
{
	char Letter = ReadChar();
	DisplayVowelCheckResult(IsVowel(Letter),Letter);
}