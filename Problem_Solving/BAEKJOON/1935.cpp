#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void)
{
	int n;
	int a[26];
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	stack<double> st;
	double res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		// 1. 피연산자면 스택에 저장
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			st.push(a[s[i]-'A']);
		}
		// 2. 그렇지 않다면
		else
		{
			// 3. 피연산자 두개를 스택에서 꺼낸다.
			double y =st.top();
			st.pop();
			double x = st.top();
			st.pop();
			// 4. 연산자에 해당하는 연산을 수행해서 스택에 다시 집어 넣는다.
			switch (s[i])
			{
			case '+':
				st.push(x + y);
				break;
			case '-':
				st.push(x - y);
				break;
			case '*':
				st.push(x*y);
				break;
			case '/':
				st.push(x / y);
				break;
			}
		}
	}
	// 5. 2가 끝나면 스택에 남아있는 값이 최종 결과이다.
	cout << fixed;
	cout.precision(2);
	cout << st.top() << '\n';
}
