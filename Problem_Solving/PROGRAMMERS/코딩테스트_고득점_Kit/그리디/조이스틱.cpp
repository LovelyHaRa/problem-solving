#include <string>
#include <vector>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }
int sum(vector<int> t) {
	int res = 0;
	for (int i : t) {
		res += i;
	}
	return res;
}

int solution(string name) {
	int answer = 0;
	int n = name.size();
	// 1. 각 문자 별로 이동 횟수를 저장
	vector<int> count(n);
	for (int i = 0; i < n; i++) {
		// 1-1. 알파벳을 반으로 쪼개 이동 횟수를 계산 했을 때, 최솟값을 대입
		count[i] = min(name[i] - 'A', 'Z' - name[i] + 1);
	}
	// 2. 이동 방법 결정
	int where = 0;
	while (1) {
		// 3. 현재 위치에 있는 이동 횟수 누적
		answer += count[where];
		count[where] = 0;
		// 4. 이동횟수를 모두 저장했으면(모두 0이면) 종료
		if (!sum(count))
			break;
		// 5. 각각의 방향으로 계산되지 않은 이동 횟수가 있을 때 까지 이동
		int left = 0, right = 0;
		int left_move = where, right_move = where;
		// 5-1. 왼쪽으로 이동
		while (count[left_move] <= 0) {
			left++;
			left_move = left_move <= 0 ? (n - 1) : left_move - 1;
		}
		// 5-2. 오른쪽으로 이동
		while (count[right_move] <= 0) {
			right++;
			right_move = (right_move + 1) % n;
		}
		// 6. 왼쪽 이동 횟수와 오른쪽 이동횟수를 비교, 최솟값으로 이동
		answer += left < right ? left : right;
		where = left < right ? left_move : right_move;
	}
	return answer;
}