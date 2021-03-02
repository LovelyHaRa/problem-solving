#include <string>
#include <vector>
#include<iostream>

using namespace std;

// 문제에서 시키는 대로 하면 된다.
vector<int> solution(string msg) {
	vector<int> answer;
	vector<string> dic;
	char a = 'A';
	// 1. 사전 초기화
	for (int i = 0; i < 26; i++) {
		string x;
		x += a + i;
		dic.push_back(x);
	}
	// 2. 탐색
	int k = 0;
	while (k < msg.size()) {
		int range = 1; // 단어 범위
		int idx = -1; // 색인 번호
		// 3. 단어가 사전에 없을 때 까지 반복
		while (k + range - 1 < msg.size()) {
			string t = msg.substr(k, range); // 단어 추출(1,2,3...글자)
			int find = -1; // 못찾으면 -1
			// 4. 단어 검색
			for (int i = 0; i < dic.size(); i++) {
				if (t.compare(dic[i]) == 0) {
					find = i + 1; // 찾으면 인덱스 + 1 저장
					break;
				}
			}
			// 5. 찾으면 색인 번호 갱신
			if (find >= 0) {
				range++; // 글자 수 증가
				idx = find;
				continue;
			}
			// 6. 못찾으면 중단
			else {
				break;
			}
		}
		// 7. 찾은 단어 색인번호를 저장
		answer.push_back(idx);
		// 8. 찾은 단어 사전에 저장
		dic.push_back(msg.substr(k, range));
		// 9. 단어 길이만큼 탐색 인덱스 증가
		k += range - 1;
	}
	return answer;
}

int main(void) {
	solution("KAKAO");
}