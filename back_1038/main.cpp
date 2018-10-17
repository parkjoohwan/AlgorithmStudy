#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<long long> number;
queue<long long> q;
int N;

void cal() {

	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		q.push(i);
		number.push_back(i);
		cnt++;
	}

	while (cnt <= N)
	{
		if (q.empty()) return;
		long long firstNum = q.front();
		q.pop();

		int LastNum = firstNum % 10;

		for (int i = 0; i < LastNum; i++)
		{
			number.push_back(firstNum * 10 + i);
			q.push(firstNum * 10 + i);
			cnt++;
		}
	}
}


int main() {

	cin >> N;

	cal();

	if (N >= number.size())
		cout << -1;
	else
		cout << number[N];

	system("pause");
	return 0;
}