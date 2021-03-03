#include <string>
#include <vector>
#include <queue>

using namespace std;
// 큐에 집어넣을 정보
class Word {
	public:
	string s;
	int count;
};
// 방문 여부
int visit[50];
// BFS 이용
int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	// 1. 시작값 세팅
	queue<Word> q;
	Word w;
	w.s = begin;
	w.count = 0;
	q.push(w);
	// 2. 큐가 공백일때까지 반복
	while (!q.empty()) {
		// 3. 큐애서 하나 꺼내기
		w = q.front();
		q.pop();
		// 4. target과 같으면 카운트 리턴
		if (w.s == target) {
			return w.count;
		}
		// 5. 단어 수만큼 반복
		for (int i = 0; i < words.size(); i++) {
			// 6. 해당단어가 방문되었다면 건너뛰기
			if (visit[i] == 1) {
				continue;
			}
			// 7. 철자 1개 빼고 일치여부 검사
			int count = 0;
			for (int j = 0; j < words[i].size(); j++) {
				if (w.s[j] != words[i][j]) {
					count++;
				}
				if (count > 1)
					break;
			}
			// 8. 2개 이상 일치 하면 건너뛰기 (변환할 수 없으므로)
			if (count > 1) {
				continue;
			}
			// 9. 변환 가능하면 큐에 삽입하고 방문여부 갱신
			else {
				Word tmp;
				tmp.s = words[i];
				tmp.count = w.count + 1; // 카운트 증가
				q.push(tmp);
				visit[i] = 1;
			}
		}
	}
	// 만들 수 없다면 0 리턴
	return answer;
}
