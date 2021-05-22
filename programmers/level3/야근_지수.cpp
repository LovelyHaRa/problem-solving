#include <string>
#include <vector>
#include<queue>
#include<iostream>

using namespace std;

long long solution(int n, vector<int> works) {
	long long answer = 0;
	// 우선 순위 큐를 사용하여 해결
	priority_queue<int> pq;
	for (int i = 0; i < works.size(); i++) {
		pq.push(works[i]); // 큐에 원소 삽입
	}
	int t = n;
	while (t--) {
		int x = pq.top();
		if (x == 0) return 0; // 최대값이 0이라는 의미이므로 바로 0 리턴
		pq.pop();
		pq.push(--x); // -1한 값을 다시 큐에 삽입
	}
	// 큐에 남은 값들을 제곱하여 더한 뒤 리턴
	while (!pq.empty()) {
		int x = pq.top();
		answer += x * x;
		pq.pop();
	}
	return answer;
}
