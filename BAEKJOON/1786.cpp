#include<iostream>
#include<string>
#include<vector>

using namespace std;

// N의 길이별 접두사와 접미사가 일치하는 최대 길이를 반환
vector<int> getPartialMatch(const string& N)
{
	int m = N.size();
	// KMP 탐색을 이용
	// 자기 자신의 일치하는 문자열을 구한다
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

// KMP 알고리즘을 이용해 일치하는 최초 인덱스 배열을 반환
vector<int> kmpSearch(const string& H, const string& N)
{
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N); // 미리 접미사=접두사 길이를 구한다
	int matched = 0;
	for (int i = 0; i < n; i++)
	{
		// 문자가 일치하지 않으면 pi[matched-1]만큼 건너뛴다
		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];
		// 문자가 일치하면
		if (H[i] == N[matched])
		{
			matched++;
			// 문자열이 일치하면
			if (matched == m)
			{
				ret.push_back(i - m + 1); // 인덱스 추가
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

int main(void)
{
	string t, p;
	getline(cin, t);
	getline(cin, p);
	vector<int> res = kmpSearch(t, p);
	int s = res.size();
	cout << s << '\n';
	for (int i = 0; i < s; i++)
		cout << res[i] + 1 << ' ';
	cout << '\n';
}
