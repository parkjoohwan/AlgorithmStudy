#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> cnt(26, -1);


int main() {
	string in;
	cin >> in;

	for (int i = 0; i < in.size(); i++) {
		for (int j = 0; j < cnt.size(); j++) {
			if (cnt[j] == -1 && in.at(i) == (97 + j)) {
				cnt[j] = i;
				break;
			}
		}
	}

	for (int i = 0; i < cnt.size(); i++)
		cout << cnt[i] << " ";


	return 0;
}