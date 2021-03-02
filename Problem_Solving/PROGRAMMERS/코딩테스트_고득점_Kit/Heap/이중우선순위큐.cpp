#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	// 최소 힙, 최대 힙, 큐 선언
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	queue<int> q;
	int i = 0;
	// 1. 연산 횟수 만큼 탐색
	while (i != operations.size()) {
		string oper = operations[i];
		// 2. 삽입 연산일 때
		if (oper[0] == 'I') {
			// 3. 숫자 추출(3번지부터 숫자)
			string num = operations[i].substr(2);
			int n = stoi(num);
			// 4. 힙에 삽입
			max_heap.push(n);
			min_heap.push(n);
		}
		// 5. 삭제 연산일 때
		else {
			char n = oper[2];
			// 6. 최솟값 삭제 연산일 때
			if (n == '-') {
				// 7. 힙이 비어있지 않으면
				if (!min_heap.empty()) {
					// 8. 최소 힙에서 제거
					int j = min_heap.top();
					min_heap.pop();
					// 9. 최대 힙에서도 같은 값 제거
					while (1) {
						// 9-1. 임시 큐에 모두 집어넣고 다시 삽입하는 식으로 진행
						int k = max_heap.top();
						max_heap.pop();
						if (j == k) {
							while (!q.empty()) {
								max_heap.push(q.front());
								q.pop();
							}
							break;
						}
						q.push(k);
					}
				}
			}
			// 10. 최댓값 삭제 연산일 때
			else {
				// 11. 7~9과정을 최대 힙에 대해 수행
				if (!max_heap.empty()) {
					int j = max_heap.top();
					max_heap.pop();
					while (1) {
						int k = min_heap.top();
						min_heap.pop();
						if (j == k) {
							while (!q.empty()) {
								min_heap.push(q.front());
								q.pop();
							}
							break;
						}
						q.push(k);
					}
				}
			}
		}
		i++;
	}
	// 결과 삽입
	if (!max_heap.empty())
		answer.push_back(max_heap.top());
	else
		answer.push_back(0);
	if (!min_heap.empty())
		answer.push_back(min_heap.top());
	else
		answer.push_back(0);
	return answer;
}