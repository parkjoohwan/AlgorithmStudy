	#include <iostream>
	#include <vector>
	#include <queue>
	#include <ctime>
#include <cstdlib>

	using namespace std;

	int checker(vector<int> item, int num, int total);

	void main() {

		int N, S;
		vector<int> item;
		int cnt;

		cin >> N >> S;

		for (int i = 0; i < N ; i++) {
			int t;
			cin >> t;
			item.push_back(t);
		}

		int cnt = checker(0, 0);

		cout << cnt << endl;

		system("pause");

	}
