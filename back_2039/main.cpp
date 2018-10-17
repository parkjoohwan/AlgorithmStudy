

//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int n, m;
//int map[201][201];
//vector<pair< int, int>> xy;
//queue<pair<int, int>> headtail;
//int dx[4] = { 0, 0, -1, 1 };
//int dy[4] = { -1, 1, 0, 0 };
//
//int aroundsum(int x, int y) {
//	int cnt = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//
//		if (!(nx < 0 || ny < 0 || nx >= n || ny >= m)) {
//			if (map[nx][ny] == 1)
//				cnt++;
//		}
//	}
//	return cnt;
//
//}
//
//
//void xyfinder() {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (map[i][j] == 1) {
//				if (aroundsum(i, j) == 1)
//					headtail.push({ i,j });
//				if (aroundsum(i, j) == 0) {
//					headtail.push({ i,j });
//					headtail.push({ i,j });
//				}
//			}
//		}
//	}
//}
//
//int checker(vector<pair<int, int>> tmp) {
//	int cnt = 0;
//	for (int i = 0; i < tmp.size(); i++) {
//		int tmpX = tmp[i].first;
//		int tmpY = tmp[i].second;
//
//
//		for (int j = 0; j < 4; j++) {
//			int nx = tmpX + dx[j];
//			int ny = tmpY + dy[j];
//			if (!(nx < 0 || ny < 0 || nx >= n || ny >= m)) {
//				if (map[nx][ny] == 0 && aroundsum(nx, ny) <= 1) {
//					cnt++;
//					break;
//				}
//			}
//		}
//	}
//
//	return cnt;
//}
//
//
//int main() {
//	scanf("%d %d", &n, &m);
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			scanf("%1d", &map[i][j]);
//		}
//	}
//
//	xyfinder();
//
//	int cnt = headtail.size() / 2;
//
//	while (!headtail.empty()) {
//		xy.push_back({ headtail.front().first, headtail.front().second });
//		headtail.pop();
//	}
//
//	printf("%d", checker(xy) );
//
//	system("pause");
//	return 0;
//}