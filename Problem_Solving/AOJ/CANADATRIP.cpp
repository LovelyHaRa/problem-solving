#include<iostream>
#include<vector>

using namespace std;
int n, k;
vector<int> l, m, g;

int min(int a, int b) { return a < b ? a : b; }

// 결정 문제: 0~dist까지의 거리를 달리면서 표지판을 k개 이상 볼 수 있는 여부를 반환
bool decision(int dist)
{
	int ret = 0; // 발견한 표지판 개수
	// 도시 탐색
	for (int i = 0; i < n; i++)
	{
		// 거리가 해당 도시 표지판보다 크면 범위 내에 존재함을 의미
		if (dist >= l[i] - m[i])
			ret += (min(dist, l[i]) - (l[i] - m[i])) / g[i] + 1; // 해당 도시(0지점)에도 표지판이 있으므로 +1
	}
	return ret >= k; // 표지판이 k개 이상이면 true
}

// 최적화 문제: k 표지판을 발견할 수 있는 최소 거리를 구한다(이분 탐색)
int optimize()
{
	int lo = -1, hi = 8030001; // 최대 거리
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		// 표지판을 k개 이상 발견할 수 있으면
		if (decision(mid))
			hi = mid; // 더 작은 값을 찾는다
		// 그렇지 않으면
		else
			lo = mid; // 더 큰 값을 찾는다
	}
	return hi;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		l.resize(n);
		m.resize(n);
		g.resize(n);
		for (int i = 0; i < n; i++)
			cin >> l[i] >> m[i] >> g[i];
		cout << optimize() << '\n';
	}
}
