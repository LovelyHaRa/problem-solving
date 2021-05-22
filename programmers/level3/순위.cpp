#include <string>
#include <vector>

using namespace std;
// 플로이드 와샬 알고리즘
int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	// 1. 그래프 생성
	vector<vector<bool>> g(n + 1, vector<bool>(n + 1, false));
	for (auto r : results) {
		g[r[0]][r[1]] = true; // 노드 단방향 체크
	}
	// 2.플로이드 와샬 알고리즘 이용
	// 중간지점
	for (int i = 1; i <= n; i++) {
		// 시작지점
		for (int j = 1; j <= n; j++) {
			// 끝지점
			for (int k = 1; k <= n; k++) {
				// 시작-중간 중간-끝 이 연결되어 있으면
				if (g[j][i] && g[i][k]) {
					g[j][k] = true; // 시작-끝도 연결한다.
				}
			}
		}
	}
	// 3. 그래프 탐색
	for (int i = 1; i <= n; i++) {
		// 4. 단방향이라도 연결되어있으면 카운트 증가
		// (이기든 지든 연결되어있으면 순위 확인 가능)
		int count = 0;
		for (int j = 1; j <= n; j++) {
			if (g[i][j] || g[j][i]) {
				count++;
			}
		}
		// 5. 자기 자신을 제외하고 모두 연결되어있으면 순위확인 가능
		if (count == n - 1) {
			answer++;
		}
	}
	return answer;
}
