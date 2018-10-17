#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[101][101];
bool check[101][101] = { false, };
int dx[4] = { 1, -1, 0, 0 };    
int dy[4] = { 0, 0, -1, 1 };    

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	pair<int, int> pos = make_pair(1, 1);
	q.push(make_pair(pos, 1));   
	check[1][1] = true;

	while (!q.empty()) {

		pos = q.front().first;
		int cnt = q.front().second;

		q.pop();

		if (pos.second == M && pos.first == N)
			return cnt;

		for (int i = 0; i<4; i++) {
			int nx = pos.second + dx[i];
			int ny = pos.first + dy[i];

			if (nx < 1 || ny < 1 || nx > M || ny > N)
				continue;
			if (check[ny][nx] == true)
				continue;
			if (map[ny][nx] != 1)
				continue;

			q.push(make_pair(make_pair(ny, nx), cnt + 1));
			check[ny][nx] = 1;
		}
	}
}



int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}


	cout << bfs();

	system("pause");
	return 0;
}