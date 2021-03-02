#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
// -1 : 답이 계산 안됨
// 1: 해당 입력들이 서로 대응됨
// 0: 해당 입력들이 서로 대응되지 않음
bool matchMemoized(vector<vector<int>>& cache, const string& w, const string& s, int wpos, int spos)
{
	// 메모이제이션
	int& ret = cache[wpos][spos];
	if (ret != -1) return ret;
	// w[wpos]와 s[spos]를 맞춰나간다
	while (wpos < w.size() && spos < s.size() && (w[wpos] == '?' || w[wpos] == s[spos]))
	{
		wpos++;
		spos++;
	}
	// 1. w[wpos]와 s[spos] 가 대응되지 않는다: return false
	// 2. 패턴 끝에 도달해서 끝난 경우(wpos==w.size()): s도 끝났어야 true
	if (wpos == w.size()) return ret = (spos == s.size());
	// 3. s가 끝에 도달했을 경우: 남은 패턴이 *일 경우 true일 수도 있으므로 4에서 처리
	// 4. w[wpos]=='*' 인 경우: 0부터 s.size()-1 까지 반복하는 skip을 통해
	//                          wpos+1부터의 패턴과 spos+skip 패턴을 비교해서 하나로 true이면 ture 리턴
	if (w[wpos] == '*')
		for (int skip = 0; skip+spos <= s.size(); skip++)
			if (matchMemoized(cache, w, s, wpos + 1, spos + skip)) return ret = 1;
	// 그 외의 경우 false 리턴
	return ret = 0;
}

int main(void)   
{
	int c;
	cin >> c;
	while (c--)
	{
		string w;
		cin >> w;
		int n;
		cin >> n;
		vector<string> res;
		while (n--)
		{
			string s;
			cin >> s;
			vector<vector<int>> cache(101, vector<int>(101, -1)); // 캐시, -1로 초기화
			if (matchMemoized(cache, w, s, 0, 0)) res.push_back(s);
		}
		sort(res.begin(), res.end()); // 정렬
		for (int i = 0; i < res.size(); i++) cout << res[i] << '\n';

	}
}
