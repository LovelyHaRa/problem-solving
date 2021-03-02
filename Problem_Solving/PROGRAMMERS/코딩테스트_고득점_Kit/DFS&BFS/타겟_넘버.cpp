#include <string>
#include <vector>

using namespace std;

int answer = 0;
// DFS를 이용하여 왼전 탐색
void DFS(vector<int> n, int sum, int i, int target) {
	// 종료 조건: 숫자를 모두 탐색 했을 때
	if (i == n.size()) {
		// 타겟 넘버와 총 합이 일치하면 경우의 수 추가
		if (sum == target)
			answer++;
		return;
	}

	// 해당 숫자를 더하고 뺀 값을 재귀탐색
	DFS(n, sum + n[i], i + 1, target);
	DFS(n, sum - n[i], i + 1, target);
}

int solution(vector<int> numbers, int target) {
	DFS(numbers, 0, 0, target);

	return answer;
}