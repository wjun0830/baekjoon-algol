#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int count;
	cin >> count;
	unsigned short int *left = new unsigned short int[count];
	unsigned short int *right = new unsigned short int[count];
	for (int y = 0; y < count; y++) {
		scanf("%hu", &left[y]);scanf("%hu", &right[y]);
	}
	for (int y = 0; y < count; y++) {
		unsigned short int M, N;
		M = left[y]; N = right[y];
		unsigned short int c = M > N ? M : N;
		short int *marr = new short int[c + 1]{ 0, };
		short int *narr = new short int[c + 1]{ 0, };
		int i = 2;
		while (1) {
			while (M % i == 0) {
				M = M / i;
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
		int minmul = 1;
		unsigned short int t = c;
		for (int i = 1; i <= t; i++) {
			if (marr[i] > narr[i]) {
				minmul *= pow(i, marr[i]);
			}
			else if (marr[i] <= narr[i]) {
				minmul *= pow(i, narr[i]);
			}
		}
		std::cout << minmul << endl;
		delete[] marr;
		delete[] narr;
	}
}