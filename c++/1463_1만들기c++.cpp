#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> Q;
	int X;
	int flag = 0;
	cin >> X;
	int count = 0;
	Q.push(X);
	while (1) {
		int sz = Q.size();
		int ele;
		for (int i = 0; i < sz; i++) {
			ele = Q.front();
			Q.pop();
			if (ele == 1)
				break;
			if (ele % 3 == 0) {
				Q.push(ele / 3);
			}
			if (ele % 2 == 0) {
				Q.push(ele / 2);
			}
			Q.push(ele - 1);
		}
		if (ele == 1)
			break;
		count++;
	}
	cout << count << endl;
}