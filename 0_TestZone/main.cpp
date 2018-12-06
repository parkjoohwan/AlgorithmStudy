#include <string>
#include <vector>
#include <iostream>
using namespace std;

char d[5] = { 'a','i','e','o','u' };

int main() {
	string in;
	cin >> in;

	vector<int> idx;

	string out;
	for (int i = 0; i < in.length(); i++) {
		for (int j = 0; j < 5; j++) {
			if (in.at(i) == d[j])
			{
				idx.push_back(i);
			}
		}	
	}

	
	int f = 0, b = idx.size()-1;
	int chkf = idx[f], chkb = idx[b];
	for (int i = 0; i < in.length(); i++) {
		if (i != chkf) {
			out += in.at(i);
		}
		else {
			out += in.at(chkb);
			f++; b--;
			if(f<idx.size() && b >= 0)
			chkf = idx[f];
			chkb = idx[b];
		}
	}

	cout << out;

}