#include <iostream>
#include <string>
#include <queue>
using namespace std;

class xy {
public:
	int x;
	int y;
	xy() {
		x = 0;
		y = 0;
	}
	xy(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

int main() {
	int M, N;
	queue<xy> q;
	cin >> M >> N;
	int **arr = new int*[N];
	int **arr1 = new int*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[M];
		arr1[i] = new int[M];
	}
	int temp, error;
	xy p;
	int x[4] = { 0,0,1,-1 };
	int y[4] = { 1,-1,0,0 };
	int mcnt = 0; int tcnt = 0; int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			arr[i][j] = temp;
			arr1[i][j] = 0;
			if (temp == -1)
				mcnt++;
			else if (temp >= 1)
				tcnt++;
		}
	}
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < M; k++) {
			if (arr[j][k] == 1) {
				xy enqu = xy(k, j);
				q.push(enqu);
				arr1[j][k] = 1;
			}
		}
	}
	int start = 1;
	while (1) {
		if (tcnt == N * M - mcnt) {
			break;
		}
		else {
			error = 0;
			int leng = q.size();
			for (int i = 0; i < leng; i++) {
				p = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					if (p.x + x[k] >= 0 && p.x + x[k] < M && p.y + y[k] >= 0 && p.y + y[k] < N && arr1[p.y + y[k]][p.x + x[k]] == 0 && arr[p.y + y[k]][p.x + x[k]] == 0){
						arr[p.y + y[k]][p.x + x[k]] = 1;
						tcnt++;
						xy enqu = xy(p.x + x[k], p.y + y[k]);
						q.push(enqu);
						arr1[p.y + y[k]][p.x + x[k]] = 1;
						error += 1;
					}
				}
			}
			cnt++;
		}
		if (error == 0 && start ==0) {
			cnt = -1;
			break;
		}
		start = 0;
	}
	cout << cnt;
}