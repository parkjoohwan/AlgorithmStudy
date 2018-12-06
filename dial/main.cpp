#include<iostream>
#include <vector>
using namespace std;

int calcnt(int src, int dst) {
	int roll = 0;
	for (int i = 0; i < 4; ++i) {
		int calc = abs(src % 10 - dst % 10);
		if (calc > 5) calc = 10 - calc;
		roll += calc;
		src /= 10; dst /= 10;
	}
	return roll;
}
int cntelse(int minIndex, vector<int> pass) {
	int n = pass.size();
	int** mcnt = new int*[n]();
	for (int i = 0; i < n; ++i)
		mcnt[i] = new int[n]();
	bool* chk = new bool[n]();

	chk[minIndex] = true;
	int count = 1;
	int result = 0;

	while (count < n) {
		int min = 36;
		for (int i = 0; i < n; ++i) {
			if (chk[i]) {
				for (int j = 0; j < n; ++j) {
					if (!chk[j]) {
						if (!mcnt[i][j]) {
							mcnt[i][j] = calcnt(pass[i], pass[j]);
						}
						if (mcnt[i][j] < min) {
							min = mcnt[i][j];
							minIndex = j;
						}
					}
				}
			}
		}
		chk[minIndex] = true;
		result += min;
		++count;
	}

	delete[] chk;
	for (int i = 0; i < n; ++i)
		delete[] mcnt[i];
	delete[] mcnt;

	return result;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> pass(n);

		int min = 36, minIndex = -1;
		for (int i = 0; i < n; ++i) {
			cin >> pass[i];
			int roll = calcnt(0, pass[i]);
			if (roll < min) {
				min = roll;
				minIndex = i;
			}
		}

		cout << min + cntelse(minIndex, pass) << endl;
	}

	return 0;
}
