#include <iostream>
#include <vector>

using namespace std;

vector<int> Cutter(vector<vector<int>> p) {
	int temp = p[0][0];
	vector<int> cnt(3, 0);
	bool check = false;
	if (p.size() != 3) {
		int size = p.size() / 3;
		vector<vector<int>> tempp(size);
		vector<int> tmpcnt(3, 0);
		for (int i = 0; i < p.size(); i++) {
			for (int j = 0; j < p[i].size(); j++) {
				if (temp != p[i][j]) {
					check = false;
					break;
				}
				else check = true;
			}
			if (check == false) break;
		}
		if (!check) {
			int n = 0, m = 0;
			while (1) {
				if (n == (p.size()-size) && m == p.size()) break;
				else if (m == p.size()) {
					n += size;
					m = 0;
				}
				for (int i = n; i < n + size; i++) {
					for (int j = m; j < m + size; j++) {
						tempp[i - n].push_back(p[i][j]);
					}
				}
				m += size;
				tmpcnt=Cutter(tempp);
				for(int i = 0 ; i < cnt.size() ; i ++)
					cnt[i] += tmpcnt[i];
				tempp.clear();
				tempp.resize(size);
			}
		}
		else {
			if (temp == -1)
				cnt[0]++;
			else if (temp == 0)
				cnt[1]++;
			else
				cnt[2]++;
		}
	}
	else {
		for (int i = 0; i < p.size(); i++) {
			for (int j = 0; j < p[i].size(); j++) {
				if (temp != p[i][j]) {
					check = false;
					break;
				}
				else check = true;
			}
			if (check == false) break;
		}
		if (!check) {
			for (int i = 0; i < p.size(); i++) {
				for (int j = 0; j < p.size(); j++) {
					if (p[i][j] == -1)
						cnt[0]++;
					else if (p[i][j] == 0)
						cnt[1]++;
					else
						cnt[2]++;
				}
			}
		}
		else {
			if (temp == -1)
				cnt[0]++;
			else if (temp == 0)
				cnt[1]++;
			else
				cnt[2]++;
		}
	}
	return cnt;
}
int main() {
	int n;
	vector<int> cnt(3,0);
	cin >> n;
	vector<vector<int>> paper(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int input;
			cin >> input;
			paper[i].push_back(input);
		}
	}

	cnt = Cutter(paper);
	
	for (int i = 0; i < cnt.size(); i++)
		cout << cnt[i] << endl;


	system("pause");
	return 0;
}