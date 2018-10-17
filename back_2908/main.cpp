#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	string str;
	int temp;
	vector<string> num;

	getline(cin, str);

	for (stringstream sts(str); (sts >> temp);) {
		num.push_back(temp);
	}

	cout << word.size() << endl;

}