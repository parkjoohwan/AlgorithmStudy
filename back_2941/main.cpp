#include <iostream>
#include <string>
using namespace std;

string ca[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main() {
	string in;
	int cnt = 0;
	cin >> in;

	for (int i = 0; i < 8; i++) {
		while (in.find(ca[i]) != -1) {
			in.replace(in.find(ca[i]), ca[i].size()," ");
			cnt++;
		}
	}

	if (in.size() > 0) {
		for (int i = 0; i < in.size(); i++) {
			if ( in[i] >= 97)
				cnt++;
		}
		cout << cnt;
	}
	else
		cout << cnt;



	return 0;
}