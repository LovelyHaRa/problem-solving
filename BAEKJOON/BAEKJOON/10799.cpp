#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	int top = 0, res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			top++;
		else
		{
			top--;
			if (s[i - 1] == '(' && i > 0)
				res += top;
			else

				res += 1;
		}
	}
	cout << res << '\n';
}