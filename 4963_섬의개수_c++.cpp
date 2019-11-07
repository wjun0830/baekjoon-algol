#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
typedef struct element {
	int h;
	int w;
}element;


int main() {
	int w, h;
	int xw[8] = { 0,1,1,1,0,-1,-1,-1 };
	int yh[8] = { -1,-1,0,1,1,1,0,-1 };
	queue<element> q;
	while (true) {
		int land = 0;
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;
		int **arr;
		arr = (int**)malloc(sizeof(int*) * h);
		for (int i = 0; i < h; i++) {
			arr[i] = (int*)malloc(sizeof(int)*w);
		}
		int **arr11;
		arr11 = (int**)malloc(sizeof(int*) * h);
		for (int i = 0; i < h; i++) {
			arr11[i] = (int*)malloc(sizeof(int)*w);
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &arr[i][j]);
				arr11[i][j] = 0;
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 1 && arr11[i][j] == 0) {
					element e;
					e.h = i;
					e.w = j;
					q.push(e);
					arr11[i][j] = 1;
					while (!q.empty()) {
						element e1 = q.front();
						q.pop();
						for (int k = 0; k < 8;k++) {
							if (e1.h + yh[k] >= 0 && e1.h + yh[k] < h && e1.w + xw[k] >= 0 && e1.w + xw[k] < w && arr[e1.h + yh[k]][e1.w + xw[k]] == 1 && arr11[e1.h + yh[k]][e1.w + xw[k]] == 0) {
								element e2; 
								e2.h = e1.h + yh[k];
								e2.w = e1.w + xw[k];
								arr11[e1.h + yh[k]][e1.w + xw[k]] = 1;
								q.push(e2);
							}
						}
					}
					land++;
				}
			}
		}
		printf("%d\n", land);
	}
}