#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits.h>
using namespace std;
//2156포도주시식
int main() {
	int len, max;
	cin >> len;
	int *arr = new int[len];
	int *num = new int[2];
	int *num1 = new int[2];
	for (int i = 0; i < len; i++) {
		scanf("%hd", &arr[i]);
	}
	num[0] = arr[0];
	num[1] = num[0] + arr[1];
	num[2] = num[1] > num[0] + arr[2] ? num[1] : num[0] + arr[2];
	num[2] = num[2] > arr[1] + arr[2] ? num[2] : arr[1] + arr[2];
	for (int i = 3; i < len; i++) {
		num[i] = num[i - 3] + arr[i-1] + arr[i] > num[i - 2] + arr[i] ? num[i-3] + arr[i-1] + arr[i] : num[i-2] + arr[i];
		num[i] = num[i] > num[i - 1] ? num[i] : num[i - 1];
	}	
	max = num[len - 1] > num[len - 2] ? num[len - 1] : num[len - 2];
	cout << max;
}