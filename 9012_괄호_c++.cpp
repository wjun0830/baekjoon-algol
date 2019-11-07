#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, lcnt, rcnt;
	cin >> N;
	string *Paren = new string[N];
	for(int i = 0; i < N; i++)
		cin >> Paren[i];
	for(int i = 0; i < N; i++) {
		if (Paren[i].front() != '(' || Paren[i].back() != ')') {
			cout << "NO" << endl;
			continue;
		} else {
			lcnt = 0; rcnt = 0;
			for (string::iterator iter = Paren[i].begin(); iter != Paren[i].end() && lcnt >= rcnt; ++iter) {
				if (*iter == '(')
					lcnt++;
				else
					rcnt++;
			}
			if (lcnt == rcnt)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}