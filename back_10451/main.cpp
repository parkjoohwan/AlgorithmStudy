#include <iostream>
using namespace std;

int main() {
	int T, N;
	int arr[1000];
	bool check[1000] = { false, };
	int j = 0, cnt = 0;
	cin >> T;

	while (T > 0) {
		cnt = 0;
		j = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			check[i] = false;
		}
		for (int i = 1; i <= N; i++) {
			if (check[i] != true) {
				j = arr[i];
				while (j != i) {
					check[j] = true;
					j = arr[j];
				}
				cnt++;
			}
		}
		cout << cnt << endl;
		T--;
	}

	system("pause");
	return 0;
}