#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

char alp[6] = { 'A', 'D', 'O', 'P', 'Q', 'R' };

int T;
string in1, in2;

int main() {

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> in1 >> in2;

		bool ans = false;

		if (in1.length() == in2.length()) {
			for (int j = 0; j < in1.length(); j++) {
				char tmp1 = in1.at(j);
				char tmp2 = in2.at(j);

				bool hashole1 = false;
				bool hashole2 = false;

				for (int k = 0; k < 6; k++) {
					if (tmp1 == alp[k])
						hashole1 = true;
					if (tmp2 == alp[k])
						hashole2 = true;
				}


				if (hashole1 && hashole2)
					ans = true;
				else if (tmp1 == 'B' && tmp2 == 'B')
					ans = true;
				else if (!hashole1 && !hashole2 && tmp1 != 'B' && tmp2 != 'B')
					ans = true;
				else {
					ans = false;
					break;
				}
			}
		}


		if (ans)
			cout << "#" << i + 1 << " SAME" << endl;
		else
			cout << "#" << i + 1 << " DIFF" << endl;
	}


	return 0;
}
