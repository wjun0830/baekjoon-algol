#include <iostream>

int main() {
	int arr[10];
	int leftover[10];
	int totalcnt = 0;
	for (int i = 0; i < 10; i++) {
		int a;
		std::cin >> a;
		arr[i] = a;
		leftover[i] = a % 42;
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			if (leftover[j] == a % 42) {
				cnt++;
			}
		}
		if (cnt == 0) {
			totalcnt++;
		}
	}
	std::cout << totalcnt << std::endl;
}