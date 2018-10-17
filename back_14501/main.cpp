#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}


int main() {
	int N;

	scanf("%d", &N);

	vector<int> T(N + 1);
	vector<int> P(N + 1);

	for (int i = 1; i <= N; i++)
	{
		int t, p;
		scanf("%d %d", &t, &p);
		T[i] = t;
		P[i] = p;
	}
	
	vector<int> sumpay(N + 2, 0);
	int mp = 0;

	/*if (T[1] <= N)
		sumpay[1] = P[1];*/

	for (int i = 2; i <= N+1; i++) {
		for (int j = 1; j < i; j++) {
			if (i - j >= T[j])
				sumpay[i] = max(sumpay[i], P[j] + sumpay[j]);
		}
	}

	for (int i = 0; i <= N+1; i++)
		mp = max(mp, sumpay[i]);

	printf("%d", mp);


	system("pause");
	return 0;
}