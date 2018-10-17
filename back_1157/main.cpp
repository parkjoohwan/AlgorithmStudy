#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int count[26] = { 0, };
	int tempChar;
	int bigCount = 0;
	int sameCount = 0;
	cin >> str;


	for( int i = 0 ; i < str.length(); i++ )
	{
		tempChar = str.at(i);
		if (tempChar < 97)
			count[tempChar - 65]++;
		else
			count[tempChar - 97]++;
	}

	for (int i = 0; i < 26; i++) {
		if (count[i] > bigCount) {
			bigCount = count[i];
			tempChar = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (count[i] == bigCount)
			sameCount++;
	}

	if (sameCount > 1) {
		cout << "?" << endl;
		return 0;
	}
	else {
		cout << (char)(tempChar + 65) << endl;
		return 0;
	}
	
}