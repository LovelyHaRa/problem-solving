#include<iostream>
#include<string>
#include<vector>

using namespace std;

string w;

bool matchMemorize(vector<vector<int>>& cache, const string& s, int wpos, int spos)
{
	// 메모제이션
	int& ret = cache[wpos][spos];
	if (ret != -1) return ret;
	// 패턴과 문자열 매칭
	while (wpos < w.size() && spos < s.size() && (w[wpos] == '?' || w[wpos] == s[spos]))
		return ret = matchMemorize(cache, s, wpos + 1, spos + 1);
	// 패턴이 끝났을 경우 문자열도 같이 끝나면 true
	if (wpos == w.size()) return ret = (spos == s.size());
	// 패턴이 *일 경우 현재 문자를 포함하는 것과 건너뛰는 것 두가지를 재귀탐색 하여 
	// 둘 중 하나라도 true를 반환하면 true
	if (w[wpos] == '*')
		return ret = (matchMemorize(cache, s, wpos + 1, spos) || (spos < s.size() && matchMemorize(cache, s, wpos, spos + 1)));
	// 그 외의 경우 false
	return ret = false;
}

int main(void)
{	
	cin >> w;
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		vector<vector<int>> cache(101, vector<int>(101, -1)); // 캐시
		if (matchMemorize(cache, s, 0, 0)) cout << s << '\n';
	}
}