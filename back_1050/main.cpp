#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int N;
int STR[100];
int INT[100];
int PNT[100];

int nowStr = 1;
int nowInt = 1;
int nowPnt = 0;

set<int> doQustList;

bool isCanTry(int n) {
	if (nowStr >= STR[n] && nowInt >= INT[n])
		return true;
	return false;
}

int max(int a, int b) {
	return a > b ? a : b;
}

void doQuest() {
	for (int i = 0; i < N; i++) {
		if (isCanTry(i))
		{
			nowStr += STR[i];
			nowInt += INT[i];
			nowPnt += PNT[i];

			STR[i] = 0;
			INT[i] = 0;
			PNT[i] = 0;
			doQustList.insert(i);
		}
	}
}

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> STR[i] >> INT[i] >> PNT[i];
	}

	int temp = 2;

	while (true) {

		doQuest();
		if (temp == (nowStr + nowInt + nowPnt))
			break;


	}

		





	return 0;
}