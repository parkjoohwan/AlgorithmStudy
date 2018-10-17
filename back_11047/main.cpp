#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

int cal(vector<int> coin , int k) {
	int sum = 0;
	int cnt = 0;
	int tmp = coin.size() - 1;
	while (!(sum == k)) {
		if (sum + coin[tmp] <= k) {
			sum += coin[tmp];
			cnt++;
		}
		else if(tmp > 0)
			tmp--;
	}

	return cnt;
}


int main() {

	int N, k, ans;
	vector<int> coin;
	scanf("%d %d", &N, &k);

	for (int i = 0; i < N; i++)
	{
		int input;
		scanf("%d", &input);
		coin.push_back(input);
	}

	printf("%d\n", cal(coin, k));

	system("pause");
	return 0;
}