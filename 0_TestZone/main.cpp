#include<iostream>
#include<algorithm>
using namespace std;

bool sosoo(int n) {
	if (n == 1) return false;
	for (int i = 2; i < n; i++)
		if (n%i == 0) return false;
	return true;
}

int counter(int n) {
	int cnt=0;
	for (int i = n+1; i <= 2 * n; i++) {
		if (sosoo(i)) cnt++;
	}

	return cnt;
}


int main(void) {
	
	while (true) {
		int a;
		cin >> a;
		if (a == 0) break;

		cout << counter(a) << endl;
	}

	return 0;
}
