#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//1929 소수구하기

int main() {
	int min, max;
	scanf("%d %d", &min, &max);
	
	bool ar[1000001] = { false };
	ar[1] = true;
	int c = max / 2 - 1;
	for (int i = 2; i < c; i++) {
		if (ar[i] == true) continue;
		for (int j = 2; i*j <= max; j++) {
			ar[i*j] = true;
		}
	}
	
	for (int i = min; i <= max; i++) {
		if (ar[i] == false) {
			printf("%d\n", i);
		}
	}
}