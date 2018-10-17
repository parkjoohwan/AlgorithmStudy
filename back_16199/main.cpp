#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {

	int y, m, d;
	int by, bm, bd;

	int out1, out2, out3;
	
	scanf("%d %d %d", &by, &bm, &bd);
	scanf("%d %d %d", &y, &m, &d);

	if (y > by && m == bm && d >= bd)
		out1 = y - by;
	else if (y > by && m > bm)
		out1 = y - by;
	else if (y == by)
		out1 = 0;
	else
		out1 = y - by-1;

	out2 = y - by + 1;
	out3 = y - by;

	printf("%d\n", out1);
	printf("%d\n", out2);
	printf("%d\n", out3);

	getchar();
	getchar();
	return 0;
}