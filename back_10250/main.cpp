#include <iostream>

using namespace std;

int T, H, W, N;

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		int nh=1, nw=1, tmp=1;
		while (tmp != N) {
			tmp++;
			if (nh < H)
				nh++;
			else {
				nh = 1;
				nw++;
			}
		}
		if (nw < 10)
			cout << nh << 0 << nw << endl;
		else
			cout << nh << nw << endl;
	}

	return 0;
}