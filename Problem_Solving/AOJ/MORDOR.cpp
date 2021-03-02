#include<iostream>
#include<vector>
#include "rmq.h"

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c;
	cin >> c;
	while (c--)
	{
		int n, q;
		cin >> n >> q;
		vector<int> h(n), maxh(n); // 최소높이, 최대높이
		for (int i = 0; i < n; i++)
		{
			cin >> h[i];
			maxh[i] = -h[i]; // 음수로 저장해서 최대값을 구할 수 있도록 한다
		}
		// 구간 최소 트리 생성
		range_min_query<int> rngLow(h);
		range_min_query<int> rngHigh(maxh);
		// 구간별 쿼리결과 출력
		for (int i = 0; i < q; i++)
		{
			int a, b;
			cin >> a >> b;
			cout << -rngHigh.query(a, b) - rngLow.query(a, b) << '\n';
		}
	}
}