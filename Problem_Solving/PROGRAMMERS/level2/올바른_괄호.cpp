#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
	// 스택 카운터로 해결 가능
	int top = 0;
	for (int i = 0; i < s.size(); i++) {
		s[i] == '(' ? top++ : top--;
		// 괄호가 )로 시작되면 무조건 false
		if (top < 0) return false;
	}
	// top이 남아있으면 올바르지 않은 문자열
	return !top;
}
