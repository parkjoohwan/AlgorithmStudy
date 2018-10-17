#include <iostream>
#include <string>
using namespace std;

int m, d;
string day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT" ,"SUN" };
int max[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };

int main() {
	cin >> m >> d;
	int dcnt=0;

	for (int i = 1; i < m; i++) {
		dcnt += max[i];
	}
	dcnt += d-1;

	cout << day[dcnt % 7];

	system("pause");
	return 0;
}