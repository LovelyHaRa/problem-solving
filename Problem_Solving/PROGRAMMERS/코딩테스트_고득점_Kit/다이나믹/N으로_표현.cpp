#include <string>
#include <vector>

using namespace std;

int answer = -1;

void dfs(int N, int number, int count, int prev) {
	int t = N;
	// 1. 종료조건1 : 최솟값이 8을 초과하면 리턴
	if (count > 8) {
		answer = -1;
		return;
	}
	// 2. 종료조건2 : 주어진 수와 현재까지 계산된 수가 같을 때
	if (number == prev) {
		// 2-1. 최초발견이거나 최솟값일 경우 저장
		if (answer == -1 || answer > count) {
			answer = count;
			return;
		}
	}
	// 3. 완전탐색
	for (int i = 0; i < 8 - count; i++) {
		// 3-1. 사칙연산 수행
		dfs(N, number, count + i + 1, prev + t);
		dfs(N, number, count + i + 1, prev - t);
		dfs(N, number, count + i + 1, prev*t);
		dfs(N, number, count + i + 1, prev / t);
		// 3-2. t값에 N 이어 붙이기
		t = t * 10 + N;
	}
}

int solution(int N, int number) {
	dfs(N, number, 0, 0);
	return answer;
}
