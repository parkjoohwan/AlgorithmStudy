#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<vector>

using namespace std;

int cal(vector<vector<int>> arr, pair<pair<int, int>, pair<int, int>> ijxy) {
	int i = ijxy.first.first;
	int j = ijxy.first.second;
	int x = ijxy.second.first;
	int y = ijxy.second.second;
	int sum = 0;

	for (int a = i-1; a < x; a++)
		for (int b = j-1; b < y; b++)
			sum += arr[a][b];

	return sum;
}

int main() {

	int N, M, K;

	scanf("%d %d", &N, &M);

	vector<vector<int>> arr(N);
	vector<pair<pair<int, int>, pair<int, int>>> ijxy;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int input;
			scanf("%d", &input);
			arr[i].push_back(input);
		}
	}

	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		int in1,in2,in3,in4;
		scanf("%d %d %d %d", &in1,&in2,&in3,&in4);
		ijxy.push_back({ { in1,in2 }, { in3,in4 } });
		printf("%d\n", cal(arr, ijxy[i]));
	}


	

}