#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	int tcnt = 0;
	int *arr = new int[N];
	for (int i = 0; i < N; i++) 
		cin >> arr[i];
	for (int i = 0; i < N; i++) {
		int k = arr[i];
		int count = 0;
		if (k == 1) {
			count += 1;
		}
		else {
			for (int j = 2; j <= k / 2 + 1; j++) {
				if (k % j == 0 && j < k) {
					count += 1;
					break;
				}
			}
		}
		if (count == 0)
			tcnt += 1;

	}
	cout << tcnt;
}