#include <iostream>

using namespace std;

int in[8];
int main() {

	for (int i = 0; i < 8; i++) {
		cin >> in[i];
	}

	bool checkA = true;
	bool checkD = true;
	for (int i = 0; i < 8; i++) {
		if (in[i] != i + 1)
			checkA = false;
		if (in[i] != 8 - i)
			checkD = false;
	}

	if (checkA)
		printf("ascending\n");
	else if (checkD)
		printf("descending\n");
	else
		printf("mixed\n");





	return 0;
}