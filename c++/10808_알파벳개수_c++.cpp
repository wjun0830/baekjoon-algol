#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main() {
	char S[100];
	scanf("%s", &S);
	int i = strlen(S);
	int arr[26]{ 0, };
	for (int j = 0; j < i; j++) {
		arr[S[j] - 97]++;
	}
	for (int j = 0; j < 26; j++) {
		printf("%d ", arr[j]);
	}
}