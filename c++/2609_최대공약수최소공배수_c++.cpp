#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	unsigned short int M,N,a,b;
	cin >> a >> b;
	int c = a > b ? a : b;
	short int *marr = new short int[c+1] {0, };
	short int *narr = new short int[c+1] {0, };
	int i = 2;
	M = a; N = b;
	while (1) {
		while (M % i == 0) {
			M = M /i;
			marr[i]++;
		}
		i += 1;
		if (M == 1)
			break;
	}
	i = 2;
	while (1) {
		while (N % i == 0) {
			N = N / i;
			narr[i]++;
		}
		i += 1;
		if (N == 1)
			break;
	}
	int maxele = 1;
	int minmul = 1;
	int t = M > N ? a : b;
	
	for (int i = 1; i <= t; i++) {
		if (marr[i] > narr[i]) {
			minmul *= pow(i, marr[i]);
			maxele *= pow(i, narr[i]);
		}
		else if (marr[i] <= narr[i]) {
			minmul *= pow(i, narr[i]);
			maxele *= pow(i, marr[i]);
		}
	}
	std::cout << maxele << endl << minmul;
}