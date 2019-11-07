#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int member[52][52] = { 0, };
	int n, a, b, c;
	scanf("%d", &n);
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == -1 && b == -1) break;
		member[a][b] = 1;
		member[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j && member[i][j] == 0)
				member[i][j] = 1e8;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				member[i][j] = min(member[i][j], member[i][k] + member[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (member[i][j] == 1e8)
				member[i][j] = 0;
		}
	}
	//int *arr = new int[n + 1];
	int *maxset = new int[n+1];
	for (int i = 0; i < n + 1; i++) {
		member[i][0] = 0;
		maxset[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			member[i][0] = max(member[i][0], member[i][j]);
		}
	}
	int mini = 100;
	for (int i = 1; i <= n; i++) {
		if (mini > member[i][0])
			mini = member[i][0];
	}
	int size = 0;
	int j = 1;
	for (int i = 1; i <= n; i++) {
		if (mini == member[i][0]) {
			size++;
			maxset[j] = i;
			j++;
		}
	}
	printf("%d %d\n", mini, size);
	for (int i = 1; i <= size; i++) {
		printf("%d ", maxset[i]);
	}

}