#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	int flag = 1;
	for (int i = 0; i < s.size(); i++) {
		// 1. 공백 후 첫문자일 때
		if (flag && s[i] != ' ') {
			// 소문자이면 대문자 변경
			if (s[i] >= 'a' && s[i] <= 'z') {
				s[i] -= 32;
			}
			flag = 0;
		}
		// 2. 공백이면 플래그 설정
		else if (s[i] == ' ') {
			flag = 1;
		}
		// 3. 그외에는 대문자이면 소문자로 변경
		else {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] += 32;
			}
		}
		answer += s[i];
	}
	return answer;
}