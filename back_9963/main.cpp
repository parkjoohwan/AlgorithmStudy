#include <iostream>

using namespace std;

int n, ans = 0;
bool col[11] = { false, };
bool on[21] = { false, };
bool under[21] = { false, };

void solve(int r) {
	if (r > n)
	{
		ans++;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!col[i] && !on[r + i] && !under[n + (r - i) + 1]) {
			col[i] = on[r + i] = under[n + (r - i) + 1] = true;
			solve(r + 1);
			col[i] = on[r + i] = under[n + (r - i) + 1] = false;
		}
	}

}

int main()
{
	cin >> n;
	solve(1);
	cout << ans;

	system("pause");
	return 0;
}