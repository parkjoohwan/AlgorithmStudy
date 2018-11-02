#include <iostream>

using namespace std;
int T;
long long x, y;



int main() {
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> x >> y;
		long long dis = y - x, n=1, pow, max, min, cnt=0;

		while (true) {
			pow = n * n;
			min = pow - n + 1;
			max = pow + 1 + n - 1;
			if (min <= dis && dis <= max) {
				if (min <= dis && dis <= pow) cnt = (n << 1) - 1;
				else cnt = n << 1;
				break;
			}
			n++;
		}

		cout << cnt << endl;
	}


	return 0;
}