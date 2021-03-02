#include<iostream>
#include<string>
#include<vector>

using namespace std;
// N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해
// pi[]를 계산한다
// pi[i]=N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
vector<int> getPartialMatch(const string& N)
{
	int m = N.size();
	vector<int> pi(m, 0);
	// KMP로 자기 자신을 찾는다.
	// N을 N에서 찾는다. begin=0이면 자기 자신을 찾아버리니깐 안된다!
	int begin = 1, matched = 0;
	// 비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록한다.
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

vector<int> getPrefixSuffix(const string& s)
{
	vector<int> ret, pi = getPartialMatch(s);
	int k = s.size();
	while (k > 0)
	{
		// s[..k-1]는 답이다.
		ret.push_back(k);
		// s[..k-1]의 접미사도 되고 접수다도 되는 문자열도 답이다.
		k = pi[k - 1];
	}
	return ret;
}

int main(void)
{
	string f, m;
	cin >> f >> m;
	vector<int> res = getPrefixSuffix(f + m);
	// 오름차순 출력
	for (auto i = res.rbegin(); i != res.rend(); i++)
		cout << *i << ' ';
	cout << endl;
}