
#include <iostream>

using namespace std;

long long dp[101] = { 0 };
int n;

long long max(int a, int b) {
	return a > b ? a : b;
}

long long counter() {

	//bool buffer = false;
	long long temp;
	/*dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= n; i++) {
		if (!buffer) {
			if (dp[i - 3] * 2 >= dp[i - 1] + 1) {
				dp[i] = max(2 * dp[i - 3], dp[i]);
				buffer = true;
				temp = dp[i - 3];
			}
			else {
				dp[i] = max(dp[i - 1] + 1, dp[i]);
			}
		}
		else if (buffer) {
			if (dp[i - 3] * 2 < dp[i - 1] + temp)
				dp[i] = max(dp[i - 1] + temp, dp[i]);
			else {
				dp[i] = max(dp[i - 3] * 2, dp[i]);
				temp = dp[i - 3];
			}
		}
			
	}*/

	for (int i = 1; i <= n; i++) {
		dp[i] = i;
		dp[i] = max(dp[i], dp[i - 1] + 1);
		for (int j = 3; j<10; j++) {
			if (i - j >= 0)dp[i] = max(dp[i - j] * (j - 1), dp[i]);
		}
	}


	return dp[n];

}


int main() {
	
	cin >> n;

	cout << counter() << endl;

	system("pause");
	return 0;
}