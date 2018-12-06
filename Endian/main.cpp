#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct bytes {
	char byte_1;
	char byte_2;
	char byte_3;
	char byte_4;
};

int main()
{
	int count = 0;

	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		int input;
		int output;
		struct bytes *in = (struct bytes *) &input;
		struct bytes *out = (struct bytes *) &output;

		scanf("%d", &input);

		out->byte_1 = in->byte_4;
		out->byte_2 = in->byte_3;
		out->byte_3 = in->byte_2;
		out->byte_4 = in->byte_1;

		printf("%d\n", output);
	}

	return 0;
}
