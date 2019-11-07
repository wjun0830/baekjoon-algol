#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	int *arr = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	int array[300][2];
	array[0][0] = arr[0];array[0][1] = 0;
	array[1][0] = array[0][0] + arr[1]; array[1][1] = array[0][1] + arr[1];
	array[2][0] = array[1][1] + arr[2]; 
	array[2][1] = array[0][0] > array[0][1] ? array[0][0] + arr[2] : array[0][1] + arr[2];
	for (int i = 3; i < num; i++) {
		array[i][0] = array[i - 1][1] + arr[i];

		array[i][1] = array[i-2][0] > array[i-2][1] ? array[i-2][0] + arr[i] : array[i-2][1] + arr[i];
	}
	int max = array[num-1][0] > array[num-1][1] ? array[num-1][0] : array[num-1][1];
	cout << max << endl;
}