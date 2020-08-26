#include <string>
#include <vector>

using namespace std;

int visit[200]; // 정점 탐색 여부

// DFS
void dfs(int start, vector<vector<int>> &computers, int n) {
	visit[start] = 1; // 정점 방문 체크
	for (int i = 0; i < n; i++) {
		// 해당 정점에서 가장 빨리 탐색되는 곳 재귀호출
		if (computers[start][i] && !visit[i]) {
			dfs(i, computers, n);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	// 1. 네트워크 수만큼 탐색
	for (int i = 0; i < n; i++) {
		// 2. DFS 하나당 네트워크 하나이므로 끝날 때마다 answer 추가
		if (!visit[i]) {
			dfs(i, computers, n);
			answer++;
		}
	}
	return answer;
}