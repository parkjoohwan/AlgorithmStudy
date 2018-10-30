#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
int in;
void jug(int n) {

	for (int i = 1; i <= n; i++) {

		if (i < 100)
			cnt++;

		else {
			int tmp1 = i % 10;
			int tmp2 = (i / 10) % 10;
			int tmp3 = i / 100;
			if (tmp2 - tmp1 == tmp3 - tmp2)
				cnt++;
		}

	}
}


int main() {

	cin >> in;

	jug(in);

	cout << cnt << endl;

	return 0;
}