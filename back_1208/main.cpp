#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N, S, arr[40];

void func(int pos, int end, int sum, vector<int>& vi) {
	if (pos == end) {
		vi.push_back(sum);
		return;
	}
	func(pos + 1, end, sum, vi);
	func(pos + 1, end, sum + arr[pos], vi);
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	vector<int> L, R;
	func(0, N / 2, 0, L);
	func(N / 2, N, 0, R);

	sort(R.begin(), R.end());
	long long ans = 0;

	for (int val : L) {
		int target = S - val;
		auto hi = upper_bound(R.begin(), R.end(), target);
		auto lo = lower_bound(R.begin(), R.end(), target);
		ans += hi - lo;
	}

	if (S == 0) {
		--ans;
	}
	cout << ans << endl;

	system("pause");
}