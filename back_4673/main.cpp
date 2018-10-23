#include <iostream>
#include <vector>

using namespace std;

bool num[10001] = { true };

void jug() {

	for (int i = 1; i <= 10000; i++)
	{
		int tmp = i;
		int n = i;
		while (true) {
			if (tmp / 10 == 0) {
				n += tmp % 10;
				num[n] = false;
				break;
			}
			else if (tmp / 10 >= 10) {
				n += tmp % 10;
				tmp = tmp/10
			}
		}
	}
}


int main() {


	jug();

	for (int i = 1; i <= 10000; i++)
		if (num[i]) cout << i << endl;

	return 0;
}