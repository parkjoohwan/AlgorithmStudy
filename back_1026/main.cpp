#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;


int cal(vector<int> a, vector<int> b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int sum = 0;

	for (int i = 0; i < a.size(); i++) {
		sum += a[i] * b[a.size() - 1 - i];
	}
	return sum;
}

int main() {

	cin >> n;

	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	cout << cal(a, b);

	system("pause");
	return 0;
}