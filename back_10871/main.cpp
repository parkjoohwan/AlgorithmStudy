#include <iostream>

using namespace std;

int N, X;
int item[10000];


int main() {

	cin >> N >> X;

	for (int i = 0; i < N; i++) {
		cin >> item[i];
	}

	for (int i = 0; i < N; i++) {
		if (item[i]< X)
		{
			cout << item[i] << " ";
		}
	}

	system("pause");

	return 0;
}