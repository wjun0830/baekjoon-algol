#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int cost[101][101] = { 0, };
	int n, m, s, f, c;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &s,&f,&c);
		if (cost[s][f] == 0)
			cost[s][f] = c;
		else cost[s][f] = min(cost[s][f], c);
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
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(cost[i][j] != 1e8)
			printf("%d ", cost[i][j]);
			else printf("0 ");
		}
		printf("\n");
	}
}