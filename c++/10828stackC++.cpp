#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class stack {
private:
	int arr[10000];
	int topcnt;
public:
	void push(int item) {
		arr[topcnt] = item;
		topcnt++;
	}
	void pop() {
		if (topcnt > 0) {
			cout << arr[topcnt - 1] << endl;
		}
		else {
			cout << "-1" << endl;
		}
		arr[topcnt - 1] = 0;
		if (topcnt > 0) {
			topcnt--;
		}
		else topcnt = 0;
	}
	void size() {
		cout << topcnt << endl;
	}

	void empty() {
		if (topcnt == 0) {
			cout << "1" << endl;
		}
		else {
			cout << "0" << endl;
		}
	}

	void top() {
		if (topcnt == 0) {
			cout << "-1" << endl;
		}
		else{
			cout << arr[topcnt - 1] << endl;
		}
	}

	stack() {
		topcnt = 0;
	}
};

int main() {
	int count;
	cin >> count;
	stack stk = stack();
	string input;
	int a;

	for (int i = 0; i < count; i++) {
		cin >> input;
		
		if (input.compare("push") == 0) {
			cin >> a;
			stk.push(a);
		}
		else if (input.compare("pop") == 0){
			stk.pop();
		}
		else if (input.compare("size") == 0) {
			stk.size();
		}
		else if (input.compare("empty") == 0) {
			stk.empty();
		}else {
			stk.top();
		}


	}
}
