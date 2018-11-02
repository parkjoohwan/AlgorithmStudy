#include <iostream>

using namespace std;

int cnt[10] = { 0, };

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n, mcnt=0;
	cin >> n;

	if (n == 0) cnt[0]++;

	while (n != 0) {
		cnt[n % 10]++;
		n /= 10;
	}

	if ((cnt[6] + cnt[9]) % 2 == 0)
		mcnt = (cnt[6] + cnt[9])/ 2;
	else
		mcnt = (cnt[6] + cnt[9])/ 2 + 1;

	for (int i = 0; i < 10; i++) {
		if(i!=6 && i!=9)
		mcnt = max(mcnt, cnt[i]);
	}

	cout << mcnt << endl;
	
	return 0;
}

