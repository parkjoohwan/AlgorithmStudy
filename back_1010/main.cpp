#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<vector>

using namespace std;

long long counter(int W, int E) {
	if ( W == 0 || W == E) return 1;
	else if (W == 1) return E;
	long long cnt = 1;

	for (int i = W+1; i <= E ; i++) {
		cnt = cnt * i / (i - W);
	}

	return cnt;
}

int main() {

	int T;
	scanf("%d", &T);
	vector<int> W(T), E(T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &W[i], &E[i]);
	}

	for (int i = 0; i < T; i++)
		printf("%ld\n", counter(W[i],E[i]));




	system("pause");
	return 0;
}