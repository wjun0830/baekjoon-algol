#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int len;
	cin >> len;
	priority_queue<int, vector<int>, greater<int>> pq;
	int a = 0;
	for (int i = 0; i < len; i++) {
		scanf("%d", &a);
		pq.push(a);
	}
	while (!pq.empty()) {
		printf("%d\n", pq.top());
		pq.pop();
	}
}