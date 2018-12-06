#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int arr[10001] = { 0, };

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int in;
		scanf("%d", &in);
		arr[in]++;
	}

	for (int i = 1; i < 10000; i++) {
		if (arr[i] != 0) {
			for (int j = 0; j < arr[i]; j++)
				printf("%d\n", i);
		}
	}

	return 0;

}