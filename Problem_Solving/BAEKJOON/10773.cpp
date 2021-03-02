// 스택 문제
#include<iostream>
#include<stack>

using namespace std;

int main(void)
{
	stack<int> s;
	int k;
	cin >> k;
	// 시키는대로 하면 됨
	int res = 0;
	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;
		if (!n) // 0일 때
		{
			res -= s.top(); // 스택값 빼줌
			s.pop();
		}
		else
		{
			// 스택 누적
			res += n;
			s.push(n);
		}
	}
	cout << res << '\n';
}