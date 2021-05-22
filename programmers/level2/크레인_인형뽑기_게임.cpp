#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> s;
	// 1. 크레인 이동 횟수만큼 탐색
	for (int i = 0; i < moves.size(); i++) {
		// 2. 현재 위치 인덱스로 저장(-1)
		int location = moves[i] - 1;
		// 3. 현재 위치에서 세로로 탐색
		for (int j = 0; j < board.size(); j++) {
			// 4. 인형이 처음 발견되면
			if (board[j][location] > 0) {
				// 5. 스택 최상단 인형과 똑같으면 2개 없애기
				if (!s.empty() && s.top() == board[j][location]) {
					answer += 2;
					s.pop();
				}
				// 6. 아니면 스택에 추가
				else {
					s.push(board[j][location]);
				}
				// 7. 격자에서 제거
				board[j][location] = 0;
				break;
			}
		}
	}
	return answer;
}
