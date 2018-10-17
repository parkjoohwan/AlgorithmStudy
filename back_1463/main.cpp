#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>

using namespace std;

int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}


int counter(int n) {
	vector<int> arr(n + 1,INT_MAX-1);
	arr[1] = 0;

	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0) arr[i] = min(arr[i / 2] + 1, arr[i]);
		if (i % 3 == 0) arr[i] = min(arr[i / 3] + 1, arr[i]);
		
	}

	return arr[n];
}

int main() {

	int n;

	scanf("%d", &n);

	printf("%d", counter(n));

	return 0;
}