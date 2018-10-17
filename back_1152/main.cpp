#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


int main() {
	string str, temp;
	vector<string> word;

	getline(cin, str);

	for (stringstream sts(str); (sts >> temp);) {
		word.push_back(temp);
	}

	cout << word.size() << endl;

	return 0;
}