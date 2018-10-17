#include <iostream>
using namespace std;

int main() {

	int n, k;
	int money[100] = { 0 };
	int make[10001] = { 0 };
	cin >> n >> k;

	for (int i = 0; i < n; i++) 
		cin >> money[i];

	make[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if( j - money[i] >= 0 ) make[j] += make[j - money[i]];
		}
	}
	cout << make[k];
	
	system("pause");

	return 0;
}