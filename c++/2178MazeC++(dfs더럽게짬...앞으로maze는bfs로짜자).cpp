#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int s, t;
vector<int> vec;
void search(int **maze, int **copy, int **cop1, int x, int y, int cnt) {
	int directionX[4] = { 1, 0, -1, 0 };
	int directionY[4] = { 0, 1, 0, -1 };
	cop1[y][x] = cnt;
	if (x == s-1 && y == t-1) {
		vec.push_back(cnt);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (x + directionX[i] >= 0 && x + directionX[i] < s && y + directionY[i] >= 0 && y + directionY[i] < t && maze[y + directionY[i]][x + directionX[i]] == 1 && (copy[y + directionY[i]][x + directionX[i]] == 0 || cop1[y + directionY[i]][x + directionX[i]] > cnt+1)) {
			
			copy[y + directionY[i]][x + directionX[i]] = 1;
			search(maze, copy, cop1, x + directionX[i], y + directionY[i], cnt+1);
		}
	}

	return;
}

int main() {
	int y, x;
	
	cin >> y >> x;
	s = x;
	t = y;
	int a = x * y;
	int **arr = new int*[y]; 
	int **cop = new int*[y];
	int **cop1 = new int*[y];
	for (int i = 0; i < y; ++i) {
		arr[i] = new int[x]; 
		cop[i] = new int[x];
		cop1[i] = new int[x];
	}
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			scanf("%1d", &arr[i][j]);
			cop[i][j] = 0;
			cop1[i][j] = 0;
		}
	}
	cop[0][0] = 1;
	int count = 1;
	search(arr, cop, cop1, 0, 0, count);
	int siz = vec.size();
	int mincnt = 10000;
	for (int i = 0; i < siz; i++) {
		int tmp = vec[i];
		if (tmp < mincnt)
			mincnt = tmp;
	}
	cout << mincnt << endl;
}