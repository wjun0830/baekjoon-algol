#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int fib[46] = { 0 };
	fib[1] = 1;
	fib[2] = 1;
	int n;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	printf("%d", fib[n]);
}