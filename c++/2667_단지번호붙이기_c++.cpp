#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
//2667단지번호붙이기
int group(int **map, bool **map1, int i, int j, int len, int cnt) {
	int x[4] = { 0,0,1,-1 };
	int y[4] = { 1,-1,0,0 };
	for (int a = 0; a < 4; a++) {
		if (i + y[a] >= 0 && i + y[a] < len && j + x[a] >= 0 && j + x[a] < len && map[i + y[a]][j + x[a]] == 1 && !map1[i + y[a]][j + x[a]]) {
			map1[i + y[a]][j + x[a]] = true;
			cnt += 1;
			cnt = group(map, map1, i + y[a], j + x[a], len, cnt);
		}
	}
	return cnt;
}

int main() {
	int len;
	cin >> len;
	priority_queue<int, vector<int>, greater<int>> pq;
	int **map = new int*[len];
	bool **map1 = new bool*[len];
	for (int i = 0; i < len; i++) {
		map[i] = new int[len];
		map1[i] = new bool[len] {false, };
	}
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (map[i][j] == 1 && map1[i][j] == false) {
				map1[i][j] = true;
				pq.push(group(map, map1, i, j, len, 1));
			}
		}
	}
	cout << pq.size() << endl;
	while (!pq.empty()) {
		printf("%d\n", pq.top());
		pq.pop();
	}
}