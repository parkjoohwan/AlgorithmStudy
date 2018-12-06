#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

int num[1000000];
int sort[1000000];

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sort[k++] = list[i++];
		else
			sort[k++] = list[j++];
	}

	if (i>mid) {
		for (l = j; l <= right; l++)
			sort[k++] = list[l];
	}
	else {
		for (l = i; l <= mid; l++)
			sort[k++] = list[l];
	}
	for (l = left; l <= right; l++) {
		list[l] = sort[l];
	}
}

void merge_sort(int list[], int left, int right) {
	int mid;

	if (left<right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}

	merge_sort(num, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", num[i]);
	}

	return 0;
}