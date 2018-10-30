#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	string ta, tb;
	for (int i = 2; i >= 0; i--) {
		ta += a.at(i);
		tb += b.at(i);
	}

	if (ta > tb)
		cout << ta;
	else
		cout << tb;



	return 0;
}