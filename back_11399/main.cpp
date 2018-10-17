#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
	int N, ans=0;
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> time;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		pq.push(input);
	}

	int temp = 0;
	while (!pq.empty())
	{
		temp += pq.top();
		pq.pop();
		time.push_back(temp);
	}

	for (int i = 0; i < time.size(); i++)
		ans += time[i];

	printf("%d\n", ans);

	system("pause");
	return 0;
}