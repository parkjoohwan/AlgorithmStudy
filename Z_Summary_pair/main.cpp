#include<iostream>
#include<utility>	// pair 사용을 위함
#include<string>
#include<vector>
#include<algorithm>	// sort 사용을 위함
using namespace std;

int main(void) {
	vector<pair<int, int> > v;

	vector<vector<int>> items = { { 100,30 },{ 120,250 },{ 80,80 },{ 200,110 } };


	v.push_back(pair <int, int>(items[0][0], 0));
	v.push_back(pair <int, int>(items[1][0], 1));
	v.push_back(pair <int, int>(items[2][0], 2));
	v.push_back(pair <int, int>(items[3][0], 3));

	cout << "=== After sort === " << endl;

	vector<pair<int, int> >::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << "[" << iter->first << "," << iter->second << "]" << endl;
	}

	cout << endl;
	sort(v.begin(), v.end());
	cout << "=== After sort === " << endl;

	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << "[" << iter->first << "," << iter->second << "]" << endl;
	}


	system("pause");


	return 0;
}
