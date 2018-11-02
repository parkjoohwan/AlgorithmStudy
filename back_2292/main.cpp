#include <iostream>

using namespace std;

long long n;

int main() {

	cin >> n;
	long long cnthome = 1 ;
	int i = 0;
	while (cnthome < n) {
		i++;
		cnthome = cnthome + i * 6;
	}

	cout << i + 1 << endl;



	return 0;
}