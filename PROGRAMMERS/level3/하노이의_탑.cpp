#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void move(int from, int to) {
	answer.push_back({ from,to });
}

void hanoi(int n, int from, int by, int to) {
	// 기저사례: n==1
	if (n == 1)
		move(from, to);
	else {
		hanoi(n - 1, from, to, by); // 1 -> 3 -> 2
		move(from, to); // 옮기기
		hanoi(n - 1, by, from, to); // 3 -> 1 ->2
	}
}

vector<vector<int>> solution(int n) {
	hanoi(n, 1, 2, 3);
	return answer;
}
