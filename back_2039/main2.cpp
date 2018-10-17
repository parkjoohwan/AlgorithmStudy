#include <iostream>
using namespace std;

char Map[201][201];
int r, c;

void getGrid() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> Map[i][j];
}

void markArea(int a, int b) {
	Map[a][b] = '2';
	if (a - 1 >= 0 && Map[a - 1][b] == '1') markArea(a - 1, b);
	if (a + 1 < r && Map[a + 1][b] == '1') markArea(a + 1, b);
	if (b - 1 >= 0 && Map[a][b - 1] == '1') markArea(a, b - 1);
	if (b + 1 < c && Map[a][b + 1] == '1') markArea(a, b + 1);
}

int countNeighbors(int a, int b) {
	int cnt = 0;

	if (a - 1 >= 0 && Map[a - 1][b] != '0') cnt++;
	if (a + 1 < r && Map[a + 1][b] != '0') cnt++;
	if (b - 1 >= 0 && Map[a][b - 1] != '0') cnt++;
	if (b + 1 < c && Map[a][b + 1] != '0') cnt++;
	return(cnt);
}

bool seeIfExtend(int a, int b) {
	if (a - 1 >= 0 && Map[a - 1][b] == '0') if (countNeighbors(a - 1, b) == 1) return false;
	if (a + 1 < r && Map[a + 1][b] == '0') if (countNeighbors(a + 1, b) == 1) return false;
	if (b - 1 >= 0 && Map[a][b - 1] == '0') if (countNeighbors(a, b - 1) == 1) return false;
	if (b + 1 < c && Map[a][b + 1] == '0') if (countNeighbors(a, b + 1) == 1) return false;
	return true;
}

bool IsAnEnd(int a, int b) {
	if ((countNeighbors(a, b) == 0 || countNeighbors(a, b) == 1)) {
		if (seeIfExtend(a, b)) {
			return true;
		}
		else {
			markArea(a, b);
			return false;
		}
	}
	else
		return false;
}

bool checkIfSnake(int a, int b) {
	int neighbors = countNeighbors(a, b);
	if (neighbors == 1 || neighbors == 0) {
		Map[a][b] = '2';
		return seeIfExtend(a, b);
	}
	if (neighbors > 2) {
		markArea(a, b);
		return false;
	}
	Map[a][b] = '2';

	if (a - 1 >= 0 && Map[a - 1][b] == '1')
		return checkIfSnake(a - 1, b);
	else
		if (a + 1 < r && Map[a + 1][b] == '1')
			return checkIfSnake(a + 1, b);
		else
			if (b - 1 >= 0 && Map[a][b - 1] == '1')
				return checkIfSnake(a, b - 1);
			else
				if (b + 1 < c && Map[a][b + 1] == '1')
					return checkIfSnake(a, b + 1);
}


bool startSnake(int a, int b) {
	int neighbors = countNeighbors(a, b);

	if (countNeighbors(a, b) == 0) return true;
	Map[a][b] = '3';
	if (a - 1 >= 0 && Map[a - 1][b] == '1')
		return checkIfSnake(a - 1, b);
	else
		if (a + 1 < r && Map[a + 1][b] == '1')
			return checkIfSnake(a + 1, b);
		else
			if (b - 1 >= 0 && Map[a][b - 1] == '1')
				return checkIfSnake(a, b - 1);
			else
				if (b + 1 < c && Map[a][b + 1] == '1')
					return checkIfSnake(a, b + 1);
}


int countSnakes() {
	int noSnakes = 0;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			if (Map[i][j] == '1') {
				if (IsAnEnd(i, j)) {
					if (startSnake(i, j)) {
						noSnakes++;
					}
					markArea(i, j);
				}
			}
		}
	return noSnakes;
}

int main() {
	cin >> r >> c;
	while (r > 0 || c > 0) {
		getGrid();

		cout << countSnakes() << endl;

		cin >> r >> c;
	}

	return 0;
}