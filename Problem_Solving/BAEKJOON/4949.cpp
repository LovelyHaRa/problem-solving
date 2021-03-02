// 스택 문제
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void)
{
	string str;

	while (1)
	{
		stack<char> s;
		getline(cin, str);
		// 종료 조건
		if (str[0] == '.' && str.length()==1)
			break;
		int i = 0;
		int flag = 1;
		// 1. 닫는 괄호일때
		// 2. 스택을 이용하여 괄호짝이 맞는지 검사
		// 3. 맞으면 pop
		// 4. 2의 조건이 아니면 no
		// 5. 여는 괄호는 push
		// 6. 문자열 순회가 끝나면 yes
		for (int i = 0; i < str.length(); i++)
		{
			// 1
			if (str[i] == ')')
			{
				// 2
				if (!s.empty() && s.top() == '(')
					s.pop(); // 3
				else
				{
					// 4
					flag = 0;
					break;
				}
			}
			// 1
			else if (str[i] == ']')
			{
				// 2
				if (!s.empty() && s.top() == '[')
					s.pop(); // 3
				else
				{
					// 4
					flag = 0;
					break;
				}
			}
			// 5
			else if (str[i] == '(' || str[i] == '[')
				s.push(str[i]);
		}
		// 6
		if (flag && s.empty())
			cout << "yes" << '\n';
		else
			cout << "no" << '\n'; // 4
	}
}
