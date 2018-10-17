#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> str;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {

	string input;
	for (int i = 0; i < 5; i++) {
		cin >> input;
		str.push_back(input);
	}

	int maxstr=0;
	for (int i = 0; i < 5; i++) {
		maxstr = max(str[i].size(), maxstr);
	}

	for (int j = 0; j <= maxstr; j++) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i].size() <= j)
				continue;
			else if( str[i][j] != '\0')
				cout << str[i][j];
		}
	}


	system("pause");
	return 0;
}