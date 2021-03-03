#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1; // 차가 한대 이상이므로 1부터 시작
	// 1. 진입 지점을 기준으로 오름차순 정렬
	sort(routes.begin(), routes.end());
	// 2. 첫 차량의 진출 지점을 기준으로 초기화
	int cur = routes[0][1];
	// 3. 탐색
	for (int i = 0; i < routes.size() - 1; i++) {
		// 4. 현재 차량의 진출 지점이 기준지점 보다 작으면
		// 기준 지점을 갱신한다
		if (cur > routes[i][1]) {
			cur = routes[i][1];
		}
		// 5. 다음 차량의 진입지점보다 기준지점이 작으면
		// 겹치지 않으므로 카메라 대수 증가 및 기준지점 갱신(다음차량의 진출지점)
		if (cur < routes[i + 1][0]) {
			cur = routes[i + 1][1];
			answer++;
		}
	}
	return answer;
}
