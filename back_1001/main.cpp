#include <iostream>
#include <vector>
#include <math.h>
#include <utility>



using namespace std;


int checker(pair<int, int> jo, pair<int, int> back, int r1, int r2) {

	double distance;
	int dx = jo.first - back.first;
	int dy = jo.second - back.second;
	distance = sqrt(pow(dx, 2) + pow(dy, 2));

	if ( distance == 0 && r1 == r2)
		return -1;
	else if ( distance == (r1 + r2) || ( (distance != 0) && (distance == abs(r1-r2) ) ))
		return 1;
	else if ( distance > (r1 + r2) || distance < abs(r1-r2))
		return 0;
	else
		return 2;
}


int main()
{
	int N;
	vector<pair<int, int>> jo;
	vector<pair<int, int>> back;
	vector<int> r1;
	vector<int> r2;

	cin >> N;


	for (int i = 0; i < N; i++) {
		int x, y, r;
		cin >> x >> y;
		jo.push_back(make_pair(x, y));
		cin >> r;
		r1.push_back(r);
		cin >> x >> y;
		back.push_back(make_pair(x, y));
		cin >> r;
		r2.push_back(r);
	}

	for( int i = 0 ; i < N ; i ++)
		cout << checker(jo[i], back[i], r1[i], r2[i]) << endl;



	system("pause");
	return 0;
}
