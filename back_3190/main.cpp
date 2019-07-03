#include <iostream>
#include <list>
#include <queue>
#include <string>

using namespace std;

int N, K, L;

int dirX[4] = { 0,1,0,-1 };
int dirY[4] = { 1,0,-1,0 };

int returndirection(string dir, int now) {
	if (dir == "D")
	{
		now++;
	}
	else
	{
		now--;
	}

	if (now >= 0)
		return now % 4;
	else
		return 4 + now;
}

list<pair<int,int>> isApple(list<pair<int, int>> a, int x, int y) {
	for (pair<int,int> temp : a) {
		if (temp.first == x && temp.second == y) {
			a.remove(temp);
			break;
		}
	}
	return a;
}

bool isCrash(int x, int y) {
	if (x == 0 || y == 0 || x > N || y > N )
		return true;
	else
		return false;
}

bool isBodyCrash(int x, int y, queue<pair<int, int>> body) {
	while (!body.empty()) {
		if (body.front().first == x && body.front().second == y)
			return true;
		body.pop();
	}
	
	return false;
}


int main() {

	cin >> N >> K;

	list<pair<int, int>> apples;

	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		apples.push_back(make_pair(x, y));
	}

	cin >> L;

	queue<pair<int, string>> snakeaction;
	queue<pair<int, int>> snakebody;

	for (int i = 0; i < L; i++)
	{
		int time;
		string dir;

		cin >> time >> dir;
		snakeaction.push(make_pair(time, dir));
	}

	int nowdir = 0, nowX = 1, nowY = 1;
	int time = 0;

	int bodylength = 1;
	snakebody.push(make_pair(nowX, nowY));

	while (!isCrash(nowX, nowY)) {

		if (!snakeaction.empty() && time == snakeaction.front().first) {
			nowdir = returndirection(snakeaction.front().second, nowdir);
			snakeaction.pop();
		}

		nowX += dirX[nowdir];
		nowY += dirY[nowdir];

		int nowapplecnt = apples.size();
		apples = isApple(apples, nowX, nowY);

		if (nowapplecnt != apples.size()) {
			snakebody.push(make_pair(nowX, nowY));
			bodylength++;
		}
		else if(!isBodyCrash(nowX,nowY,snakebody)) {
				snakebody.pop();
				snakebody.push(make_pair(nowX, nowY));
		}
		else
		{
			time++;
			break;
		}

		time++;
	}

	cout << time;

	system("pause");
	return 0;
}