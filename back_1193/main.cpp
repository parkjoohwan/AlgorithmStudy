#include <iostream>

using namespace std;

long long n;

int main() {

	cin >> n;
	int sum=2, l=1;
	long long cnt = 1;
	while (cnt < n) {
		sum++;
		l++;
		cnt += (sum-1);
	}

	if (l % 2 == 0) {
		int u = sum - 1 - (cnt - n);
		int d = 1 + (cnt-n);
		cout << u << "/" << d;
	}
	else {
		int u = 1 + (cnt - n);
		int d = sum-1 - (cnt - n);
		cout << u << "/" << d;
	}

	return 0;
}