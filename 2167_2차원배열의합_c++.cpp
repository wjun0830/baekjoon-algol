#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int **arr = (int **)malloc(sizeof(int *)*(n+1));
	for (int i = 0; i <= n; i++) {
		arr[i] = (int*)malloc(sizeof(int)*(m+1));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int count,y1,x1,x2,y2;
	int sum;
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		sum = 0;
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		for (int i = y1; i <= y2;i++) {
			for (int j = x1; j <= x2; j++) {
				sum += arr[i][j];
			}
		}
		printf("%d\n", sum);
	}
}