#include<iostream>
#include<vector>

using namespace std;

int n, d, p, q;
vector<vector<int>> connected;
vector<int> deg;
vector<vector<double>> cache;

// days일 째에 here번 마을에 숨어있다고 가정하고
// 마지막 날에 q번 마을에 숨어있을 조건부 확률을 반환
double search(int here, int days)
{
	// 기저 사례: days가 d에 도달했을 때
	if (days == d) return (here == q ? 1.0 : 0.0);
	// 메모이제이션
	double& ret = cache[here][days];
	if (ret > -0.5) return ret;
	ret = 0.0;
	// 조건부 확률 구하기
	for (int there = 0; there < n; there++)
		if (connected[here][there])
			ret += search(there, days + 1) / deg[here];
	return ret;
}

// 개선된 버전: 뒤에서 부터 계산
double optSearch(int here, int days)
{
	// 기저 사례: days가 0에 도달했을 때
	if (days == 0) return (here == p ? 1.0 : 0.0);
	// 메모이제이션
	double& ret = cache[here][days];
	if (ret > -0.5) return ret;
	ret = 0.0;
	// 조건부 확률 구하기
	for (int there = 0; there < n; there++)
		if (connected[here][there])
			ret += optSearch(there, days - 1) / deg[here];
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n >> d >> p;
		connected.resize(n + 1, vector<int>(n + 1, 0));
		cache.resize(n + 1, vector<double>(d + 1, -1));
		deg.resize(n + 1, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> connected[i][j];
				if (connected[i][j]) deg[i]++; // 차수 구하기
			}
		}
		int t;
		cin >> t;
		vector<double> ans(t);
		// 개선된 버전
		for (int i = 0; i < t; i++)
		{
			cin >> q;
			//ans[i] = search(p, 0); // 마지막 날에 q에 숨어있을 확률을 구한다.
			//// 캐시 초기화
			//cache.clear();
			//cache.resize(n + 1, vector<double>(d + 1, -1));
			ans[i] = optSearch(q, d);
		}
		cout.precision(10);
		for (int i = 0; i < t; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		connected.clear();
		cache.clear();
		deg.clear();
	}
}