#include<iostream>

using namespace std;

int a, b, c;
int cnt[10] = { 0 };

int main() {

	cin >> a >> b >> c;
	long long mul = a * b * c;

	while (mul != 0) {
		cnt[mul % 10] += 1;
		mul /= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << cnt[i] << endl;
	




	system("pause");
	return 0;
}