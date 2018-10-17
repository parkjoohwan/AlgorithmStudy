#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
using namespace std;


int counter(int n) {
	int cnt = 0;
	int i = 2;
	vector<int> arr(n + 1, 0);
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 4; i <= n; i++) {
		arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
	}

	return arr[n];
}

int main() {

	int T,n;
	scanf("%d", &T);
	vector<int> ans;
	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		ans.push_back(counter(n));
	}
	
	for (int i = 0; i < T; i++)
		printf("%d", ans[i]);

	return 0;
}