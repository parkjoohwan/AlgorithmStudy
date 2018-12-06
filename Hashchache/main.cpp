#include <iostream>
#include <string>

using namespace std;

int CustomHash(const char *str) {

	unsigned long hash = 5381;

	int c;

	while (c = *str++)

		hash = ((hash << 5) + hash) + c;

	return hash & 0x7FFFFFFF;

}

int main() {

	/*string in;
	cin >> in;*/

	string a = "1234";

	cout << CustomHash("123");



	return 0;
}