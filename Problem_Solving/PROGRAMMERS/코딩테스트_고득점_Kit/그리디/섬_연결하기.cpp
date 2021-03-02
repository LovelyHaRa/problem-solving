#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> d; // 해당 노드의 상위노드를 나타냄

bool compare(vector<int> &a, vector<int> &b) {
	return a[2] < b[2]; // 가중치를 기준으로 정렬
}

int find(int node) {
	if (node == d[node]) return node;
	else return d[node] = find(d[node]);
}
// 크루스칼 알고리즘으로 최소 스패닝 트리를 생성한다.
int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	// 1. 가중치 기준으로 오름차순 정렬
	sort(costs.begin(), costs.end(), compare);
	d.resize(n);
	// 2. 상위노드 초기화
	for (int i = 0; i < n; i++) {
		d[i] = i; // 처음에는 자기 자신이 상위노드 값
	}
	// 3. 간선 개수만큼 탐색
	for (int i = 0; i < costs.size(); i++) {
		// 4. 시작점과 끝점과 가중치를 구한다.
		int start = find(costs[i][0]);
		int end = find(costs[i][1]);
		int cost = costs[i][2];
		// 5. start와 end가 다르면 연결되지 않음을 의미
		if (start != end) {
			d[start] = end; // 연결하고
			answer += cost; // 값 추가
		}
	}
	return answer;
}