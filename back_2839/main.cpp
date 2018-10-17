#include <iostream>
#include <vector>
using namespace std;

int N;

int min(int a, int b) {
	return a > b ? b : a;
}

int main() {
	cin >> N;
	vector<int> dp(N + 1, 5000);

	for (int i = 3; i <= N; i++) {
		if (i % 3 == 0)
			dp[i] = min(dp[i], i / 3);
		if (i % 5 == 0)
			dp[i] = min(dp[i], i / 5);
		if( (i-5)%3==0 )
			dp[i] = min(dp[i], dp[i - 5]+1);
		dp[i] = min(dp[i], dp[i - 3]+1);
	}

	for (int i = 3; i <= N; i++)
		if (dp[i] == 5000)
			dp[i] = -1;

	cout << dp[N];

	system("pause");
	return 0;

}