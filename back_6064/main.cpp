#include <iostream>

using namespace std;

int T, m, n, x, y;

int mn(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> m >> n >> x >> y;

		int cnt = x % (m + 1);
		int tmpY = x;

		for (int j = 0; j < n; j++) {
			int ty = tmpY % n == 0 ? n : tmpY % n;
			if (ty == y) {
				break;
			}

			tmpY = ty + m;
			cnt += m;
		}
		if (m * n / mn(m, n) < cnt)
			cout << -1 << endl;
		else
			cout << cnt << endl;
	}


	return 0;
}