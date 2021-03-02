#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
	bool operator()(vector<int> a, vector<int> b) {
		return a.at(1) > b.at(1); // greater
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	// 1. 시간대별 오름차순 정렬
	sort(jobs.begin(), jobs.end());
	// 2. 백터를 저장할 수 있는 우선순위 큐 선언
	priority_queue<vector<int>, vector<vector<int>>, compare> pq;
	int i = 0, time=0; // 작업단계, 진행 시간
	// 3. 큐가 비어있고 모든 작업을 완료할 때 까지 탐색
	while (i < jobs.size() || !pq.empty()) {
		// 4. 현재 작업이 진행시간보다 작아서 큐에 넣을 수 있을 때
		if (i < jobs.size() && time>=jobs[i][0]) {
			// 4-1. 큐에 삽입
			pq.push(jobs[i++]);
			// 4-2. 다른 작업도 동시간대에 들어올 수 있으므로 재탐색
			continue;
		}
		// 5. 큐가 비어있지 않으면
		if (!pq.empty()) {
			// 5-1. 작업 시간 누적
			time += pq.top()[1];
			// 5-2. 작업이 대기부터 완료할 때 까지 시간=(현재시간-들어온시간)
			answer += time-pq.top()[0];
			// 5-3. 큐에서 제거
			pq.pop();
		}
		// 6. 큐가 비어있다면 다음 작업 시간만큼 증가
		else
			time = jobs[i][0];
	}
	return answer / jobs.size();
}

int main(void) {
	solution({ { 0,3 }, { 1,9 }, { 2,6 } });
}