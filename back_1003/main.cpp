#include <iostream>

using namespace std;

int memo[40] = { 1,1, };

int fibonacci(int n) {
	if (n <= 1) return memo[n];
	else {
		if (memo[n] > 0) return memo[n];
	}
	return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		if (t == 0) cout << "1 0" << endl;
		else if (t == 1) cout << "0 1" << endl;
		else {
			fibonacci(t);
			cout << memo[t-2] << " " << memo[t-1] << endl;
		}
	}


	return 0;
}