#include <string>
#include <vector>

using namespace std;

/*
	1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
	2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다.단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다.
	3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
	  3 - 1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
	4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
	  4 - 1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
	  4 - 2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
	  4 - 3. ')'를 다시 붙입니다.
	  4 - 4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
	  4 - 5. 생성된 문자열을 반환합니다.
*/

// 올바른 괄호열인지 체크
bool check(string s) {
	int top = 0;
	for (int i = 0; i < s.size(); i++) {
		s[i] == '(' ? top++ : top--;
		// 음수가 나오면 올바르지 않은 괄호열
		if (top < 0)
			return false;
	}
	return true;
}

// 문자열을 u, v로 분라하는 함수(2)
vector<string> tokenize(string s) {
	int top = 0;
	int i = 0;
	vector<string> res(2); // u, v
	// u: 균형잡힌 괄호열: 처음을 제외하고
	//                  최초로 스택 포인터가 0이되는 순간
	do {
		s[i] == '(' ? top++ : top--;
		res[0] += s[i++];
	} while (top != 0);
	// v: u를 제외한 나머지
	res[1] = s.substr(i);
	return res;
}

string process(string u, string v) {
	// 1. u가 올바른 문자열이면(3)
	if (check(u)) {
		// v에 대해 1단계부터 다시 수행
		// (1)
		if (!v.size())
			return u;
		// (2)
		else {
			vector<string> token = tokenize(v);
			// 수행 결과를 붙이기(3-1)
			return u + process(token[0], token[1]);
		}
	}
	// 2. u가 올바르지 않은 문자열이면(4)
	else {
		// (4-1)
		string t = "(";
		// (4-2)
		if (v.size()) {
			vector<string> token = tokenize(v);
			t += process(token[0], token[1]);
		}
		// (4-3)
		t += ')';
		// (4-4)
		for (int i = 1; i < u.size() - 1; i++) {
			t += u[i] == '(' ? ')' : '(';
		}
		// (4-5)
		return t;
	}
}

string solution(string p) {
	vector<string> token = tokenize(p);
	return process(token[0], token[1]);
}
