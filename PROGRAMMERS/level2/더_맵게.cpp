#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	// 1. 오름차순 우선순위 큐에 데이터 집어넣기
	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}
	// 2. 우선순위 큐에 두개 이상 데이터가 존재하고 선출되는 값이 K 미만일 때까지 반복
	while (pq.top() < K && pq.size() > 1) {
		// 3. 첫번째와 두번째 데이터를 큐에서 추출
		int first, second;
		first = pq.top();
		pq.pop();
		second = pq.top();
		pq.pop();
		// 4. 새로운 스코빌 지수 계산 뒤 push
		pq.push(first + second * 2);
		answer++;
	}
	// 5. 어떠한 경우에도 스코빌 지수가 K를 넘지 못하는 경우 -1 출력
	if (pq.top() < K)
		return -1;
	return answer;
}
