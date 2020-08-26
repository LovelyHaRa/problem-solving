#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> getPartialMatch(const string& N)
{
	int m = N.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;
	while (begin + matched < m)
	{
		if (N[begin + matched] == N[matched])
		{
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else
		{
			if (matched == 0)
				begin++;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

// a의 접미사이면서 b의 접두사인 문자열의 최대 길이를 구한다
int maxOverlap(const string& a, const string& b)
{
	int n = a.size(), m = b.size();
	vector<int> pi = getPartialMatch(b);
	int begin = 0, matched = 0;
	while (begin < n)
	{
		// 짚더미의 해당 글자가 바늘의 해당 글자와 같다면
		if (matched < m && a[begin + matched] == b[matched])
		{
			matched++;
			if (begin + matched == n)
				return matched;
		}
		else
		{
			if (matched == 0)
				begin++;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return 0;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		string s;
		cin >> s;
		string t = s;
		reverse(t.begin(), t.end());
		cout << s.size() * 2 - maxOverlap(s, t) << '\n';
	}
}