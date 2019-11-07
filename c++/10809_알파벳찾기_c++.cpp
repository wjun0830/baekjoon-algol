#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	int c = 'a';
	for (c; c <= 'z'; c++) {
		int a = S.find(char(c)) >= 0 ? S.find(char(c)) : -1;
		cout << a << " ";
	}
}