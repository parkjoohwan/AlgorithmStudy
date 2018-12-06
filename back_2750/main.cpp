#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& n)
{
	for (int i = 0; i < n.size(); i++)
	{
		int tmp = n[i];
		for (int j = i+1; j < n.size(); j++) {
			if (n[j] <= tmp) {
				n[i] = n[j];
				n[j] = tmp;
				tmp = n[i];
			}
		}
	}
}

int main() {

	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++)
	{
		int in;
		cin >> in;
		num[i] = in;
	}

	sort(num);

	for (int i = 0; i < n; i++)
	{
		cout << num[i] << endl;
	}

	return 0;
}