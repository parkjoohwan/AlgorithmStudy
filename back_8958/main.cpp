#include <string>
#include <iostream>

using namespace std;

int n;
string temp;

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		int sum = 0;
		int add = 1;
		for (int i = 0; i < temp.size(); i++) {
			if (temp.at(i) == 'O') {
				sum += add;
				add++;
			}
			else {
				add = 1;
			}
		}
		cout << sum << endl;
	}


	return 0;
}
