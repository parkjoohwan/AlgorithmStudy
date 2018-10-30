#include <stdio.h>

int s[27] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };

int main() {

	for (char c; ~scanf("%c", &c);) s[26] += s[c - 'A'];
	printf("%d", s[26]);

	return 0;
}