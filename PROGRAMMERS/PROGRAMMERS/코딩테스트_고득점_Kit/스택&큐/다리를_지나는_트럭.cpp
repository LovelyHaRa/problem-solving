// 시뮬레이션 문제
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> q;
	int sum = 0;
	
	// 1. 큐가 비었을 때 : 큐에 트럭 추가, 무게 누적, 시간 추가
	// 2. 큐가 꽉찼을 때 : 큐에서 트럭 제거, 무게 감소
	// 3. 1,2가 아닌경우
	// 4. 무게가 초과할 경우 : 큐에 0을 추가(무게 영향없음), 시간 추가
	// 5. 4가 아닌 경우 : 1과 같은 작업

	for (int i = 0; i < truck_weights.size(); i++) {
		int k = truck_weights[i];
		while (1) {
			// 1
			if (q.empty()) {
				q.push(k);
				sum += k;
				answer++;
				break;
			}
			// 2
			else if (q.size() == bridge_length) {
				sum -= q.front();
				q.pop();
			}
			// 3
			else {
				// 5
				if (sum + k <= weight) {
					q.push(k);
					sum += k;
					answer++;
					break;
				}
				// 4
				else {
					q.push(0);
					answer++;
				}
			}
		}
	}
	// 총 시간 = 지금까지 구한시간 + 마지막 트럭이 건너는 시간(다리 길이)
	answer += bridge_length;
	return answer;
}