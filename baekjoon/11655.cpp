#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string s;
	getline(cin, s);
	string res;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			int k = s[i] - 'A';
			k = (k + 13) % 26; // Z -> A
			res += k + 'A';
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			int k = s[i] - 'a';
			k = (k + 13) % 26; // z -> a
			res += k + 'a';
		}
		else res += s[i];
	}
	cout << res << '\n';
}
