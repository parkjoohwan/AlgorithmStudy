#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N,M;
vector<string> human;
vector<string> ans;
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		human.push_back(input);
	}

	sort(human.begin(), human.end());

	for (int i = 0; i < M; i++)
	{
		string input;
		cin >> input;
		if (binary_search(human.begin(), human.end(), input))
			ans.push_back(input);
	}

	cout << ans.size();

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
		printf("%s\n", ans[i]);

	return 0;
}