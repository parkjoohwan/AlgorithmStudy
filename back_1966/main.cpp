#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {
	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, M;
		int cnt=0;
		cin >> N >> M;

		priority_queue<int, vector<int>, less<int>> pq;
		queue<pair<int, int>> q;
		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;
			pq.push(input);
			q.push({ input,i });
		}

		while (!pq.empty()) {
			int tmpP = q.front().first;
			int tmpIdx = q.front().second;
			int maxP = pq.top();

			if (tmpIdx == M && tmpP == maxP) {
				cnt++;
				break;
			}
			if (q.front().first == pq.top()) {
				cnt++;
				q.pop();
				pq.pop();
			}
			else {
				q.pop();
				q.push({ tmpP, tmpIdx });
			}
		}

		cout << cnt << endl;
	}




	system("pause");
	return 0;
}



