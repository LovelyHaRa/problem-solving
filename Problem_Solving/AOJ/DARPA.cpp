#include<iostream>
#include<vector>

using namespace std;

// 결정 문제: 그리디 알고리즘 이용
// 카메라를 지점마다 gap만큼 띄워서 설치할 수 있는 경우가 카메라 수보다 크면 true
bool decision(const vector<double>& location, int cameras, double gap)
{
	double limit = -1; // 다음 카메라 설치 최소 지점
	int installed = 0; // 설치한 카메라 대수
	// 설치 가능한 지점을 탐색
	for (int i = 0; i < location.size(); i++)
	{
		if (limit <= location[i])
		{
			installed++;
			// gap 이상 만큼 되어야 설치 가능
			limit = location[i] + gap;
		}
	}
	// 결과적으로 카메라 대수보다 많이 설치할 수 있으면 true
	return cameras <= installed;
}

// 최적화 문제: 이분법 이용
double optimize(const vector<double>& location, int cameras)
{
	double lo = 0, hi = 241;
	for (int i = 0; i < 100; i++)
	{
		double mid = (lo + hi) / 2.0;
		// mid 값이 가능한 경우라면 답은 오른쪽 구간에 존재
		if (decision(location, cameras, mid))
			lo = mid;
		// 그렇지 않다면 왼쪽 구간에 존재
		else
			hi = mid;
	}
	return lo;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n, m;
		cin >> n >> m;
		vector<double> location(m);
		for (int i = 0; i < m; i++)
			cin >> location[i];
		// 세번째 자리에서 반올림
		cout.precision(2);
		cout << fixed << optimize(location, n) << '\n';
	}
}
