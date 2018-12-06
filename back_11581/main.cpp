#include<iostream>
#include<memory.h>
using namespace std;
int a, b, k, t, start, finish;
int c[100001];

int main() {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		k = 0;
		memset(c, -1, sizeof(c));
		scanf("%d %d", &a, &b);
		start = finish = 0;

		printf("%d.", (a / b));
		int temp = a % b * 10;

		while (true) { 
			a = a % b * 10;
			if (c[a] != -1) {
				start = c[a];
				finish = k;
				break;
			}
			c[a] = k++;
		}

		for (int i = 0; i < start; i++) {
			printf("%d", temp / b);
			temp = temp % b * 10;
		}
		printf("(");
		for (int i = start; i < finish; i++) {
			printf("%d", temp / b);
			temp = temp % b * 10;
		}
		printf(")\n");
	}
	return 0;
}

