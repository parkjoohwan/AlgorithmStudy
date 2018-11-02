#include <iostream>
#include <vector>
using namespace std;

int T, k, n;

int main() {
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> k>> n;

		vector<int> temp(n);

		for (int j = 0; j < n; j++)
			temp[j] = j + 1;
	
		for (int j = 0; j < k; j++) {
			for (int l = 1; l < n; l++) {
				temp[l] = temp[l-1] + temp[l];
			}
		}

		cout << temp[n - 1] << endl;
	}

	return 0;

}