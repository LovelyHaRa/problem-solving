#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	while (1)
	{
		string s;
		cin >> s;
		if (s[0] == '0') return 0;
		int len = s.size();
		int i;
		for (i = 0; i < len / 2; i++)
		{
			int j = len - 1 - i;
			if (s[i] != s[j]) break;
		}
		// 끝까지 탐색되면 펠린드롬수
		i >= len / 2 ? cout << "yes\n" : cout << "no\n";
	}
}
