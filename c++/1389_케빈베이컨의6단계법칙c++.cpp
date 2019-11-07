#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int cost[101][101] = { 0, };
	int n, m, s, f, c;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &s,&f);
		cost[s][f] = 1;
		cost[f][s] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j && cost[i][j] == 0)
				cost[i][j] = 1e8;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}
	int *mini = new int[n+1];
	for (int i = 0; i <= n; i++)
		mini[i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] == 1e8)
				cost[i][j] = 0;
			mini[i] += cost[i][j];
		}
	}
	int minimum = 1e9;
	int kevin = 0;
	for(int i = 1; i <= n; i++){
		if (minimum > mini[i]) {
			minimum = mini[i];
			kevin = i;
		}
	}
	printf("%d\n", kevin);
}