#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	stack<char> st;
	string res; // 후위 표기식
	for (int i = 0; i < s.size(); i++)
	{
		// 1. 피연산자는 무조건 후위표기식에 추가
		if (s[i] >= 'A' && s[i] <= 'Z')
			res += s[i];
		// 2. 연산자 일때
		else
		{
			// 3. 여는 괄호는 스택에 푸시
			if (s[i] == '(')
				st.push(s[i]);
			// 4. 여는 괄호가 아니라면
			else
			{
				// 5. 스택이 비어있지 않고 여는 괄호가 나올 때 까지 반복
				while (!st.empty() && st.top() != '(')
				{
					// 6. 우선순위가 높은(*, /) 연산자 일 경우
					if ((s[i] == '*' || s[i] == '/') && s[i] != ')')
					{
						// 7. 우선순위가 낮은 연산자(+, -)를 만나면 break
						if (st.top() == '+' || st.top() == '-')
							break;
					}
					// 8. 연산자에 대해 공통으로 수행
					res += st.top(); // 후위 표기식에 스택 위쪽 값 추가
					st.pop(); // 스택 에서 제거
				}
				// 9. 닫는 괄호이면  여는 괄호 제거(top 값은 반드시 여는 괄호
				if (s[i] == ')') st.pop();
				else st.push(s[i]);
			}
		}	
	}
	// 10. 스택에 남은 연산자 후위표기식에 추가
	while (!st.empty())
	{
		res += st.top();
		st.pop();
	}
	cout << res << '\n';
}
