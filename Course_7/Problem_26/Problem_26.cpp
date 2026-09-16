#include <iostream>
#include <string>
using namespace std;

char ReadCharacter() {
	char Character;
	cout << "Please enter a character: ";
	cin >> Character;
	return Character;
}

char InvertCharacterCase(char Character) {
	if (isupper(Character)) {
		return tolower(Character);
	}
	else {
		return toupper(Character);
	}
}


int main()
{
	char Ch = ReadCharacter();
	cout << "\nCharacter after inverting case:\n";
	cout << InvertCharacterCase(Ch);
}