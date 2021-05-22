#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
	int answer = 0;
	stack<char> t;
	// 문자열 길이가 홀수이면 반드시 1개는 남는다.
	if (s.size() % 2) return 0;
	// 1. 첫문자 스택 push
	t.push(s[0]);
	// 2. 문자열 탐색
	for (int i = 1; i < s.size(); i++) {
		// 3. 스택이 비어있거나 top과 현재 문자가 일치하지 않으면 push
		if (t.empty() || t.top() != s[i]) {
			t.push(s[i]);
		}
		// 4. 그렇지 않으면 pop
		else {
			t.pop();
		}
	}
	// 5. 스택이 비어있으면 1 아니면 0 리턴
	return t.empty();
}
