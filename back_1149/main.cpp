#include<iostream>
#include <vector>

using namespace std;

int n;
int house[1001][3];
int min(int a, int b) {
	return (a > b) ? b : a;
}

int cal() {
	int dp[1001][3] = { 0 };
	int temp;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = min( dp[i-1][(j+1)%3], dp[i-1][(j+2)%3] ) + house[i][j];
		}
	}

	return min(min(dp[n][0], dp[n][1]), dp[n][2]);
}

int main() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> house[i][j];
		}
	}

	cout << cal() << endl;


	system("pause");
	return 0;
}