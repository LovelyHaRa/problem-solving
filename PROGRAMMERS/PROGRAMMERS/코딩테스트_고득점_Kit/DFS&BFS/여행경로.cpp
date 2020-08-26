#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer;
bool dfs(string from, vector<vector<string>>& tickets, vector<string>& result, vector<int>& visit, int count) {
	// 3. 경로 갱신
	result.push_back(from);
	// 4. 경로가 완성되면 정답 갱신 후 true 리턴
	if (count == tickets.size()) {
		answer = result;
		return true;
	}
	// 5. 티켓 탐색
	for (int i = 0; i < tickets.size(); i++) {
		// 6. 출발지가 같고 티켓을 쓴 적이 없다면
		if (tickets[i][0] == from && !visit[i]) {
			// 7. 해당 티켓 사용
			visit[i] = 1;
			// 7-1. 목적지를 출발지로, 카운트를 1 증가시켜 dfs 탐색
			bool success = dfs(tickets[i][1], tickets, result, visit, count + 1);
			// 7-2. 경로가 완성되면 dfs 종료
			if (success)
				return true;
			// 7-3 .티켓 사용 여부 복구
			visit[i] = 0;
		}
	}
	// 8. 경로 복구
	result.pop_back();
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> result; // 결과 경로
	vector<int> visit(tickets.size()); // 티켓 사용 여부
	// 1. 알파벳 우선출력이므로 정렬
	sort(tickets.begin(), tickets.end());
	// 2. dfs 탐색
	dfs("ICN", tickets, result, visit, 0);
	// 9. 정답 리턴
	return answer;
}