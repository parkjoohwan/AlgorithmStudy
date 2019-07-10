#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <math.h>
#include <set>
using namespace std;

// 특정 숫자에서 다른 수로 변환 가능 여부 및 소모 전구
// 0 -> 8(1)
// 1 -> 0(7), 3(6), 4(4), 7(2), 8(8), 9(6)
// 2 -> 8(2)
// 3 -> 8(4), 9
// 4 -> 8(4), 9(1)
// 5 -> 6(1), 8(2), 9
// 6 -> 8(1)
// 7 -> 0(5), 8(6), 9(3)
// 8 -> x
// 9 -> 8(1)

vector<string> zero = { "###", "#.#", "#.#", "#.#", "###" };
vector<string> own = { "..#", "..#", "..#" , "..#" , "..#" };
vector<string> two = { "###", "..#", "###", "#..", "###" };
vector<string> three = { "###", "..#", "###", "..#", "###" };
vector<string> four = { "#.#", "#.#", "###","..#", "..#" };
vector<string> five = { "###", "#..", "###", "..#", "###" };
vector<string> six = { "###", "#..", "###", "#.#", "###" };
vector<string> seven = { "###", "..#", "..#", "..#", "..#" };
vector<string> eight = { "###", "#.#", "###", "#.#", "###" };
vector<string> nine = { "###", "#.#", "###", "..#", "###" };

vector<vector<string>> Number = { zero, own, two, three, four, five, six, seven, eight, nine };

int isNumber(vector<string> panel) {
	for (int i = 0; i < 10; i++) {
		if (Number[i] == panel)
			return i;
	}
	return -1;
}

bool isCanNumber(vector<string> panel) {
	return panel[1].at(1) == '#' || panel[3].at(1) == '#' ? false : true;
}

bool isCanThisNumber(vector<string> input, vector<string> want) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			if (input[i].at(j) == '#' && want[i].at(j) != '#')
				return false;
		}
	}
	return true;
}

bool isPanelEqual(vector<string> panel1, vector<string> panel2) {
	return panel1 == panel2;
}

vector<bool> canNumbers(vector<string> panel) {
	vector<bool> needs(10, false);

	int temp = isNumber(panel);
	
	if (temp != -1)
	{
		needs[temp] = true;
		for (int i = 0; i < 10; i++)
		{
			if (isCanThisNumber(panel, Number[i]))
			{
				needs[i] = true;
			}
		}

		return needs;
	}
	else if (isCanNumber(panel)) {
		for (int i = 0; i < 10; i++)
		{
			if (isCanThisNumber(panel, Number[i])) {
				needs[i] = true;
			}
		}
	}

	return needs;
}


// pair<int, string> = 자리수, panel
vector<vector<string>> dividePanel(vector<string> panel, int n) {
	vector<vector<string>> temp(n);
	for (int i = 0; i < 5; i++) {
		string tmp = panel[i];
		int srt = 0;
		for (int j = 0; j < n; j++) {
			if (j != 0)
				srt = 3 * j + 1 * j;
			temp[j].push_back(tmp.substr(srt, 3));
		}
	}

	return temp;
}

int powTen(int i, int n) {
	return pow(10, n - 1 - i);
}

int main() {

	int n;
	vector<string> total;

	cin >> n;

	for (int i = 0; i < 5; i++) {
		string temp;
		cin >> temp;
		total.push_back(temp);
	}

	vector<vector<string>> divide = dividePanel(total, n);


	// 1. 숫자인지 판단
	// 2. 숫자가 아닌거 숫자가 될수있는지 판단
	// 3. 숫자가 아닌거 숫자가 되는데 필요한 갯수
	// 4. 완전탐색

	vector<vector<bool>> panelInfo(n);
	vector<vector<int>> panelCanNumber(n);
	for (int i = 0; i < n; i++) {
		panelInfo[i] = canNumbers(divide[i]);
		for (int j = 0; j < 10; j++) {
			/*if (panelInfo[i][j] && j != 0) {*/
			if (panelInfo[i][j]) {
				panelCanNumber[i].push_back(j*powTen(i, n));
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		if (panelInfo[i][0] && i != 0) {
			panelCanNumber[i].push_back(0);
		}
	}*/

	/*for (int i = 0; i < n; i++) {
		cout << i <<"-----"<< endl;
		for (int j = 0;  j < panelCanNumber[i].size(); j++) {
			cout << panelCanNumber[i][j] << " ";
		}
		cout << "-----" << endl << endl;
	}*/

	vector < pair<int, long long>> all(n);

	for (int i = 0; i < n; i++) {
		long long temp = 0;
		for (int j = 0; j < panelCanNumber[i].size(); j++) {
			temp += panelCanNumber[i][j];
		}
		all[i] = make_pair(panelCanNumber[i].size(), temp);
	}

	long long totalSum = 0;

	int divider = 1;

	for (int i = 0; i < n; i++) {
		divider *= all[i].first;
	}


	for( int i = 0 ; i < n ; i ++){
		int temp = 1;
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			else
				temp *= all[j].first;
		}
		totalSum += (temp*all[i].second);
	}


	//cout << totalSum << endl;
	//cout << divider << endl;

	if (divider == 0)
		cout << -1;
	else
		printf("%.5f\n", (double)totalSum / divider);

	return 0;
}