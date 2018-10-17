#include <iostream>
#include <vector>
using namespace std;
int N, K;
int main() {
	cin >> N >> K;
	int cnt = 0;
	int num = 2;
	int result;
	vector<bool> number(N + 1, false);
	while (cnt != K) {

		for (int i = num; i <= N ; i+=num ) {
			if (!number[i]) {
				number[i] = true;
				cnt++;
			}
			if (cnt == K) {
				result = i;
				break;
			}
		}

		for (int i = 3; i <= N; i++){
			if (!number[i]) {
				num = i;
				break;
			}
		}
	}

	cout << result;



	return 0;
}