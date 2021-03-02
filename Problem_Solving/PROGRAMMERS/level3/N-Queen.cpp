#include <string>
#include <vector>

using namespace std;

int N;
vector<int> col(15); // 열을 기준으로 행값을 저장
int cnt = 0;

// 절대값
int abs(int a, int b) {
	return a < b ? b - a : a - b;
}

bool isPossible(int row) {
	// 같은 행에 있거나 대각선에 존재하면 false
	for (int i = 0; i < row; i++) {
		if (col[row] == col[i] || (abs(col[row], col[i]) == abs(row, i))) return false;
	}
	return true;
}

// 백트래킹
void queen(int row) {
	if (row == N) {
		cnt++;
	}
	else {
		for (int i = 0; i < N; i++) {
			col[row] = i;
			if (isPossible(row)) {
				queen(row + 1);
			}
			else {
				col[row] = 0;
			}
		}
	}
	col[row] = 0;
}

int solution(int n) {
	N = n;
	queen(0);
	return cnt;
}