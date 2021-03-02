#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// BFS 탐색 활용
void bfs(int n, vector<vector <int>>& g, queue<int>& q, vector<int>& visit, int count) {
	// 3. 종료조건: 큐가 비어있을 때 종료
	if (q.empty()) {
		return;
	}
	// 4. 큐에서 값을 꺼냄
	int t = q.front();
	q.pop();
	// 5. 노드 수만큼 탐색
	for (int i = 1; i <= n; i++) {
		// 6. 노드 사이가 연결되어있고 방문한적이 없으면
		if (g[t][i] && visit[i] < 0) {
			// 7. 현재 거리의 +1을 방문 여부 배열에 저장 
			visit[i] = visit[t] + 1;
			// 8. 큐에 삽입
			q.push(i);
		}
	}
	// 9. 큐가 빌 때까지 재귀 탐색
	bfs(n, g, q, visit, count + 1);
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	// 1. 그래프 테이블 생성
	vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < edge.size(); i++) {
		// 에지를 표현하기 위해 1로 설정한다
		g[edge[i][0]][edge[i][1]] = g[edge[i][1]][edge[i][0]] = 1;
	}
	// BFS 큐
	queue<int> q;
	// 노드 1과의 거리를 저장함과 동시에 방문여부 확인
	vector<int> visit(n + 1, -1);
	// 문제 요구조건: 1부터 시작
	q.push(1);
	visit[1] = 0;
	// 2. BFS 탐색
	bfs(n, g, q, visit, 0);
	// 10. 정렬
	sort(visit.begin(), visit.end());
	// 11. 최댓값은 가장 오른쪽 값(오름차순 정렬)
	int max = visit[n];
	// 12. 최댓값과 달라질 때 까지 정답값 1씩 증가
	while (max == visit[n--]) {
		answer++;
	}
	return answer;
}
