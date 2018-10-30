#include <iostream>
#include <queue>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0,0, 1, -1 };
char map[12][6];
bool erase = false;
int ans = 0;

void bfs(int a, int b) {
	char tmp = map[a][b];
	int cnt = 0;
	bool vmap[12][6] = { false, };
	queue<pair<int, int>> q, vq;
	q.push({ a, b });
	vq.push({ a, b });
	while (!q.empty()) {
		cnt++;
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();

		vmap[nx][ny] = true;
		for (int i = 0; i < 4; i++) {
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (!(tx < 0 || ty < 0 || tx >= 12 || ty >= 6)) {
				if (map[tx][ty] == tmp && vmap[tx][ty] == false) {
					q.push({ tx,ty });
					vq.push({ tx,ty });
				}
			}
		}
	}

	if (cnt >= 4) {
		while (!vq.empty()) {
			int nx = vq.front().first;
			int ny = vq.front().second;
			vq.pop();
			map[nx][ny] = '.';
		}
		erase = true;
	}
}

void down() {
	for (int i = 0; i < 6; i++) {
		int idx = 11;
		for (int j = 11; j >= 0; j--) {
			if (map[idx][i] != '.')
				idx--;
			if (map[j][i] != '.' && j < idx && map[idx][i] == '.') {
				map[idx][i] = map[j][i];
				map[j][i] = '.';
				idx--;
			}
		}
	}

}


int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}

	while (true) {
		for (int i = 11; i >= 0; i--) {
			for (int j = 5; j >= 0; j--) {
				if (map[i][j] != '.') {
					bfs(i, j);
				}
			}
		}

		down();

		if (erase) {
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 6; j++) {
					cout << map[i][j];
				}
				cout << endl;
			}
			ans++;
			erase = false;
		}
		else
			break;
	}

	cout << ans << endl;


	system("pause");
	return 0;
}


