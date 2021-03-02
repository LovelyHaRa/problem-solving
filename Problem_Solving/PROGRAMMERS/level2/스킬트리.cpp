#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	// 1. 스킬트리 개수만큼 반복
	for (int i = 0; i < skill_trees.size(); i++) {
		int impossible = 0; // 스킬트리 불가능 여부
		int j = 0;
		queue<char> q, tq; // 스킬상태
		// 2. 스킬상태 업데이트
		while (j < skill.size()) {
			q.push(skill[j++]);
		}
		// 3. 스킬트리 순회
		for (j = 0; j < skill_trees[i].size(); j++) {
			int flag = 0; // 첫번째 스킬 일치여부
			// 4. 스킬트리 상태를 임시로 저장
			tq = q;
			// 5. 임시 스킬트리 순회
			while (!tq.empty()) {
				// 6. 첫번째 순회때 일치하지 않고 두번째 순회부터 일치하면 불가능
				if (flag && tq.front() == skill_trees[i][j]) {
					impossible = 1;
					break;
				}
				// 7. 첫번째 순회때 일치하면 스킬상태에서 pop
				else if (tq.front() == skill_trees[i][j]) {
					q.pop();
					break;
				}
				tq.pop();
				flag = 1;
			}
			// 8 불가능시 탐색 중단
			if (impossible) {
				break;
			}
		}
		// 9 가능 불가능 여부에 따라 정답 증가
		answer = impossible ? answer : answer + 1;
	}
	return answer;
}

int main(void) {
	solution("CBD", { "BACDE","CBADF", "AECB", "BDA" });
}