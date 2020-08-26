#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	while (1) {
		// 1. 2x2 블록 찾기
		vector<pair<int, int>> removeidx; // 2x2의 왼쪽위 좌표를 저장
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				// 없앤 블록은 건너뛰기
				if (board[i][j] == ' ') continue;
				// 2x2 블록이면 맞으면 추가
				if (board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1] && board[i][j])
					removeidx.push_back(make_pair(i, j));
			}
		}
		// 2. 종료조건: 2x2 블록이 없으면 종료
		if (removeidx.empty()) break;
		// 3. 2x2 블록 제거
		for (int i = 0; i < removeidx.size(); i++) {
			// 좌표 추출
			int x = removeidx[i].first;
			int y = removeidx[i].second;
			for (int j = x; j <= x + 1; j++) {
				for (int k = y; k <= y + 1; k++) {
					// 해당 좌표가 이미 제거되었다면 건너뛰기(중복처리)
					if (board[j][k] == ' ')
						continue;
					// 제거 후 카운팅
					board[j][k] = ' ';
					answer++;
				}
			}
		}
		// 3. 블록 아래로 떨어뜨리기
		for (int i = 0; i < n; i++) {
			int flag; // 더이상 떨어질 블록이 없는지 체크하기 위한 변수
			do {
				flag = 0;
				for (int j = 0; j < m - 1; j++) {
					// 현재 위치는 블록이 있고, 다음 위치에는 없을 때 위치 옮김
					if (board[j][i] != ' ' && board[j + 1][i] == ' ') {
						board[j + 1][i] = board[j][i];
						board[j][i] = ' ';
						flag = 1; // board가 갱신되었으므로 체크
					}
				}
			} while (flag); // board가 갱신되지 않을 때 까지 반복
		}
	}
	return answer;
}