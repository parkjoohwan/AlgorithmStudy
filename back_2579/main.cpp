#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>

using namespace std;

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int cal(vector<int> s, int n) {
	vector<int> dp(301, 0);
	dp[1] =  s[1] ;
	dp[2] = max(s[1] + s[2], s[2]);
	dp[3] = max(s[1] + s[3], s[2] + s[3]);
	
	for (int i = 3; i < n+1; i++)
		dp[i] = max(dp[i - 2] + s[i], s[i - 1] + s[i] + dp[i - 3]);


	return dp[n];
}


int main() {

	int n;

	scanf("%d", &n);

	vector<int> score(301);

	for (int i = 1; i < n+1; i++) {
		int input;
		scanf("%d", &input);
		score[i]=input;
	}

	printf("%d\n", cal(score,n));


	system("pause");
	return 0;
}