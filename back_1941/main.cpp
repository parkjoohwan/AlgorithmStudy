//완전 탐색 문제

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int checker(vector<vector<char>> arr, int cnt, int num) {
	


}



int main() {

	char S;
	vector<vector<char>> item;
	int cnt;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> S;
			item[i].push_back(S);
		}
	}

	cnt = checker(item, 0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << item[i][j];
		}
		cout << endl;
	}

	cout << cnt << endl;

	system("pause");
	return 0;
}