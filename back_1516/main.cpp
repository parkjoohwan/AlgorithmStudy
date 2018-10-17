#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define m 501

int time[m], degree[m], sol[m];	
vector<int> need[m];	
queue<int> q;

int main() {
	int n;
	cin>> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		time[i] = a; sol[i] = a;
		while (b != -1) {
			need[b].push_back(i);
			degree[i]++;
			cin >> b;
		}
	}
	for (int i = 1; i <= n; i++) {	
		if (degree[i] == 0) q.push(i);	
	}
	while (!q.empty()) {			
		int level = q.front();		
		q.pop();
		for (auto i : need[level]) {	
			degree[i]--;
			if (!degree[i]) q.push(i);
			sol[i] = max(sol[i], sol[level] + time[i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << sol[i] << endl;
	}

	system("pause");
	return 0;
}