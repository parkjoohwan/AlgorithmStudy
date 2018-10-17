#include <iostream>
#include <vector>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))

int N;
vector<int> test;

int main() {
	int T;
	int temp;

	cin >> T;
	while (T--) {
		cin >> N;
		for (int n = 0; n < N; n++) {
			cin >> temp;
			test.push_back(temp);
		}

		long long ans = 0;
		int ma = test[N - 1];

		for (int n = N - 2; n >= 0; n--) {
			if (test[n] < ma)
				ans += (ma - test[n]);
			else ma = test[n];
		}
		cout << ans << endl;
	}

	system("pause");

	return 0;
}
