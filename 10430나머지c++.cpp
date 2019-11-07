#include <iostream>

int main() {
	int arr[3];
	for (int i = 0; i < 3; i++) {
		std::cin >> arr[i];
	}
	std::cout << (arr[0] + arr[1]) % arr[2] << std::endl;
	std::cout << (arr[0] % arr[2] + arr[1] % arr[2]) % arr[2] << std::endl;
	std::cout << (arr[0] * arr[1]) % arr[2] << std::endl;
	std::cout << (arr[0] % arr[2] * arr[1] % arr[2]) % arr[2] << std::endl;
}
