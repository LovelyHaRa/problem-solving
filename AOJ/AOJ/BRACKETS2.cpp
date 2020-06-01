#include<iostream>
#include<stack>
#include<string>

using namespace std;

int matched(const string& s)
{
	stack<char> st;
	const string opening("({["), closing(")}]");
	for (int i = 0; i < s.size(); i++)
	{
		// 여는 괄호는 무조건 스택에 넣음
		if (opening.find(s[i]) != -1)
			st.push(s[i]);
		else
		{
			// 스택이 비어있으면 실패
			if (st.empty()) return false;
			// 짝이 맞지 않아도 실패
			if (opening.find(st.top()) != closing.find(s[i]))
				return false;
			// 짝이 맞으면 스택에서 제거
			st.pop();
		}
	}
	// 스택이 비어있으면 성공
	return st.empty();
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		string s;
		cin >> s;
		cout << (matched(s) ? "YES\n" : "NO\n");
	}
}