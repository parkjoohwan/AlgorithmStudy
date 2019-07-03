#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int limit_dis;
int fix_cnt;
vector<int> fix_dis;
vector<int> fix_time;
vector<int> memo;
vector<bool> fin;

void check_time(int fix_num, int total_time, vector<bool> visit) {



	if (memo[fix_num] > total_time)
	{
		memo[fix_num] = total_time;
	}
	else
		return;

	if (fix_num == fix_dis.size() - 1)
		fin = visit;

	for (int i = 1; i < fix_dis.size(); i++) {
		if (!visit[i]) {
			if (fix_dis[i] - fix_dis[fix_num] <= limit_dis)
			{
				visit[i] = true;
				check_time(i, total_time + fix_time[i], visit);
				visit[i] = false;
			}
		}
	}

	return;
}



int main() {

	cin >> limit_dis >> fix_cnt;

	fix_dis.resize(fix_cnt + 2, 0);
	fix_time.resize(fix_cnt + 2, 0);
	memo.resize(fix_cnt + 2, INT_MAX);

	int total_dis = 0;

	for (int i = 1; i < fix_dis.size(); i++)
	{
		int tmp;
		cin >> tmp;
		total_dis += tmp;
		fix_dis[i] = total_dis;
	}

	for (int i = 1; i < fix_time.size() - 1; i++)
	{
		cin >> fix_time[i];
	}

	vector<bool> visit(fix_dis.size(), false);
	check_time(0, 0, visit);

	cout << memo[memo.size() - 1] << endl;

	int cnt = 0;
	for (int i = 0; i < fin.size() - 1; i++)
		if (fin[i])
			cnt++;

	cout << cnt << endl;

	for (int i = 0; i < fin.size() - 1; i++)
		if (fin[i])
			cout << i << " ";

	system("pause");


	return 0;
}