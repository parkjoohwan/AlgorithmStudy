#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int num[10001] = { 0, };

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int t;
		scanf("%d", &t);
		num[t]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (num[i]>0) {
			for (int j = 0; j < num[i]; j++)
				printf("%d\n", i);
		}
	}

	return 0;

}