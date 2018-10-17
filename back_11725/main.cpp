#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);
	vector<vector<int>> connect(N+1);
	vector<int> parent(N+1,0);
	parent[1] = -1;

	for (int i = 0; i < N-1; i++) {
		int input1, input2;
		scanf("%d %d", &input1, &input2);
		connect[input1].push_back(input2);
		connect[input2].push_back(input1);
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < connect[1].size(); i++) {
		q.push({ 1,connect[1][i] });
	}

	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();

		parent[tmp.second] = tmp.first;

		for (int i = 0; i < connect[tmp.second].size(); i++) {
			if( parent[ connect[tmp.second][i] ] == 0 )
				q.push({ tmp.second, connect[tmp.second][i] });
		}
	}


	for (int i = 2; i < N+1; i++)
		printf("%d\n", parent[i]);


	system("pause");
	return 0;
}