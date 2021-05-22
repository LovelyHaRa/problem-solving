#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	// set 이용
	set<string> s;
	s.insert(words[0]);
	for (int i = 1; i < words.size(); i++) {
		// 탈락자 차례 : 현재 단어 위치 / 참가자수 + 1
		// 탈락자 번호 : 현재 단어 위치 % 참가자수 + 1
		// 1. 중복 단어 호출 시 탈락
		if (s.count(words[i])) {
			answer.push_back(i%n + 1);
			answer.push_back(i / n + 1);
			return answer;
		}
		// 2. 정상 단어이면 set에 추가
		if (words[i - 1][words[i - 1].size() - 1] == words[i][0]) {
			s.insert(words[i]);
		}
		// 3. 끝말잇기 룰 위반시 탈락
		else {
			answer.push_back(i%n + 1);
			answer.push_back(i / n + 1);
			return answer;
		}
	}

	return { 0,0 };
}
