#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[11] = { 0, };
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 4;
	int* num = new int[N];
	for (int i = 3; i < 10; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < N; i++) {
		cout << arr[num[i] - 1] << endl;
	}
}