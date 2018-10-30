#include <iostream> 
#include <deque> 

using namespace std;
int n, m;
deque<int> deq;
deque<int>::iterator iter;

int main() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		deq.push_back(i);

	int cnt = 0;

	for (int i = 0; i < m; i++)	{

		int now; 
		cin >> now;
		int idx = 1;

		for (iter = deq.begin(); iter < deq.end(); iter++)
		{
			if (*iter == now)
				break;
			idx++;
		}

		int left = idx - 1;
		int right = deq.size() - (idx - 1);

		if (left < right) {
			for (int i = 1; i <= left; i++) {
				deq.push_back(deq.at(0));
				deq.pop_front();
				cnt++;
			}
			deq.pop_front();
		}
		else {
			for (int i = 1; i <= right; i++) {
				deq.push_front(deq.at(deq.size() - 1));
				deq.pop_back();
				cnt++;
			}
			deq.pop_front();
		}
	}

	cout << cnt << endl;
	return 0;

}
