#include <iostream>
#include <vector>

using namespace std;

bool num[10001];

void jug() {
	int i = 1;
	while (true) {
		if (num[i] == false) {
			int tmp = i;
			int n = i;

			while (n <= 10000) {
				if (tmp / 10 == 0) {
					n += tmp % 10;
					tmp = n;
					num[n] = true;
				}
				else if (tmp / 10 >= 1) {
					n += tmp % 10;
					tmp = tmp / 10;
				}
			}
		}
		if (i >= 10000)
			break;
		i++;
	}
}


int main() {


	jug();

	for (int i = 1; i <= 10000; i++) {
		if (!num[i]) printf("%d\n", i);
	}

	return 0;
}