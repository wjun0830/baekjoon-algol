#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits.h>
using namespace std;
// DP로 풀어야함.
int main() {
	int len, max;
	cin >> len;
	int *arr = new int[len];
	int *num = new int[len] {0, };
	int *num1 = new int[len] {0, };
	for (int i = 0; i < len; i++) {
		scanf("%d", &arr[i]);
	}
	max = arr[0], num[0] = arr[0];
	//num[0] = arr[0];
	for (int i = 1; i < len; i++) {
		num[i] = num[i - 1] + arr[i] > arr[i] ? num[i - 1] + arr[i] : arr[i];
		max = max > num[i] ? max : num[i];
	}
	cout << max << endl;
}