#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool checker(vector<vector<int>> m) {
	for (int i = 0; i < m.size(); i++)
		for (int j = 0; j < m[i].size(); j++)
			if (m[i][j] == 0) return false;
	return true;
}

int daycounter(vector<vector<int>> m) {
	int day = 0;
	queue<pair<int, int>> q;

	if (checker(m))
		return 0;

	for (int i = 0; i < m.size() ; i++) {
		for (int j = 0; j < m[i].size() ; j++) {
			if (m[i][j] == 1) q.push({ i,j });
		}
	}

	while (!q.empty()) {
		int tmp = q.size();

		for (int k = 0; k < tmp; k++) {
			pair<int, int> now = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				pair<int, int> next = { now.first + dy[i], now.second + dx[i] };
				if (next.first >= 0 && next.first < m.size() && next.second >= 0 && next.second < m[0].size() 
					&& m[next.first][next.second] == 0 ) {
					q.push(next);
					m[next.first][next.second] = 1;
				}
			}
		}

		day++;
	}
	
	if (checker(m))
		return day-1;
	else
		return -1;
}

int main() {
	int M, N;
	scanf("%d %d", &M, &N);
	vector<vector<int>> map(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int input;
			scanf("%d", &input);
			map[i].push_back(input);
		}
	}

	printf("%d", daycounter(map));


	system("pause");
	return 0;
}