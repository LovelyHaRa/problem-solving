#include <string>
#include <vector>

using namespace std;

// 결정: n명까지 징검다리를 건넌 뒤 다음 사람이 건널수 있는지 여부를 반환
bool decision(const vector<int>& stones, int k, int n) {
	int cnt = 0, max = 0; // 건널 수 없는 돌의 길이, 최대 길이
	for (int i = 0; i < stones.size(); i++) {
		int k = stones[i] - n; // n명이 건넌다
		// 건널 수 없는 돌의 길이 갱신
		if (k <= 0)
			cnt++;
		else {
			max = max < cnt ? cnt : max;
			cnt = 0;
		}
	}
	// max값이 한번도 갱신 안됬을 수도 있으므로 갱신
	max = max < cnt ? cnt : max;
	// 길이가 k보다 짧아야 다음사람이 건널 수 있다
	return max < k;
}
// 최적화: 이분탐색으로 징검다리를 건널 수 있는 상태가 되는 최소의 n을 구한다
int optimize(const vector<int>& stones, int k) {
	int lo = 0, hi = 2e8; // 최소: 아무도 안건너는 경우, 최대: 돌의 개수
	// 이분 탐색
	for (int i = 0; i < 100; i++) {
		int mid = (lo + hi) / 2;
		// 징검다리가 건널 수 있는 상태이면
		if (decision(stones, k, mid))
			lo = mid; // 더 큰값을 찾아본다
		// 그렇지 않다면
		else
			hi = mid; // 더 작은 값을 찾아본다
	}
	return lo; //최솟값을 리턴 해야 하므로 lo 리턴
}

int solution(vector<int> stones, int k) {
	int answer = 0;
	return optimize(stones, k) + 1; // 1명 더 건널 수 있으므로 +1
}