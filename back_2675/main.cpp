#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		string in,out;
		cin >> n >> in;
		
		for (int i = 0; i < in.size(); i++) {
			for (int j = 0; j < n; j++) {
				out += in.at(i);
			}
		}
		cout << out << endl;
	}


	return 0;
}