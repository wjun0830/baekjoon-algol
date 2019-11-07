#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

void bfs(int start, int *check, int **arr, int size) {
	queue<int> q;
	int cnt = 0;
	q.push(start);
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		if (check[num - 1] == 0) {
			check[num - 1] = 1;
			cout << num << " ";
		}
		for (int i = 0; i < size; i++) {
			if (arr[num - 1][i] == 1 && check[i] == 0) {
				q.push(i + 1);
			}
		}
	}
}

void dfs(int start, int *check, int **arr, int size) {
	int cnt = 0;
	cout << start << " ";
	check[start - 1] = 1;
	for (int i = 0; i < size; i++) {
		if (arr[start - 1][i] == 1 && check[i] == 0 && i != start -1) {
			check[i] = 1;
			dfs(i + 1, check, arr, size);
		}
	}
	return;
}

int main() {
	int v, e, start, x, y;
	cin >> v >> e >> start;
	int** arr = new int*[v];
	for (int i = 0; i < v; ++i) {
		arr[i] = new int[v] {0, };
	}
	for (int i = 0; i < e; i++) {
		cin >> x >> y;
		arr[x - 1][y - 1] = 1;
		arr[y - 1][x - 1] = 1;
	}
	int *check = new int[v] {0, };
	dfs(start, check, arr, v);
	cout << endl;
	for (int i = 0; i < v; i++) {
		check[i] = 0;
	}
	bfs(start, check, arr, v);
}