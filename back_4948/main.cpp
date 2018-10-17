#include<iostream>
#include<vector>
#include <math.h>
using namespace std;
#define MAX 123457
int sosoo(int n) {
	vector<bool> num(2*n+1, true);

	for (int i = 2; i * i <= 2*n; i++) {
		int mult = 2;
		if (num[i]) {
			for (int j = i * mult; j <= 2*n ; j = i * mult) {
				num[j] = false;
				mult++;
			}
		}
	}
	int cnt = 0;

	for (int i = n + 1; i <= 2 * n; i++) {
		if (num[i]) cnt++;
	}

	return cnt;
}

int main(void) {


	while (true) {
		int a;
		cin >> a;
		if (a == 0) break;

		cout << sosoo(a) << endl;
	}

	return 0;
}
