#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int> pq;
	int supply = 0;
	// 1. 0일 부터 k일까지 반복
	for (int i = 0; i < k; i++) {
		// 2. 현재 일자에 보급받을 수 있으면 우선순위 큐에 저장
		if (dates[supply] == i) {
			pq.push(supplies[supply]);
			supply < supplies.size() - 1 ? supply++ : supply;
		}
		// 3. 재고가 다떨어지면 가장 많은 재고량부터 누적
		// 그래야 보급을 최소로 받을 수 있다.
		if (!stock) {
			stock += pq.top();
			pq.pop();
			answer++;
		}
		// 4. 하루의 끝은 재고소비로 마무리
		stock--;
	}
	return answer;
}
