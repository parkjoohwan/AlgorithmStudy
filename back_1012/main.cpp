#include <iostream>
#include <vector>

using namespace std;

int t, k;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<vector<int>> check(vector<vector<int>> visit,int x , int y) {

	visit[x][y] = 2;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx == visit.size() || ny == visit[0].size())
			continue;
		if (visit[nx][ny] == 1)
		{
			visit = check(visit, nx, ny);
		}
	}

	return visit;
}


int checkcnt(vector<vector<int>> map) {
	vector <vector<int>> visit = map;
	int cnt = 0;

	for (int i = 0; i < visit.size(); i++) {
		for (int j = 0; j < visit[i].size(); j++) {
			if (visit[i][j] == 1) {
				visit = check(visit, i, j);
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {

	cin >> t;

	while (t>0) {
		int mx,my,k; 
		cin >> mx >> my >> k;

		vector<vector<int>> map;

		for (int i = 0; i < mx; i++) {
			vector<int> tmp(my, 0);
			map.push_back(tmp);
		}

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}

		cout << checkcnt(map) << endl;

		t--;
	}

	system("pause");

	return 0;
}