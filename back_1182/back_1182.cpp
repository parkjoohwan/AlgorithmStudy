#include <iostream>

using namespace std;

const int MAX = 20;

int N, S;
int arr[MAX];
int result = 0;

void checker(int idx, int sum)
{
	sum += arr[idx];
	if (idx >= N)
		return;
	if (sum == S)
		result++;
	checker(idx + 1, sum - arr[idx]);
	checker(idx + 1, sum);
}



int main(void)

{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	checker(0, 0);

	cout << result << endl;

	return 0;
}