#include<iostream>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

vector<vector<double>> dist;
int n;

// 결정 문제: 거리 d이하인 기지들을 연결 했을 때 모두 연결할 수 있는지 여부 반환
bool decision(double d)
{
	// BFS 탐색
	vector<bool> visited(n, false);
	visited[0] = true;
	queue<int> q;
	q.push(0);
	int seen = 0; // 연결 개수
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		seen++;
		for (int there = 0; there < n; there++)
		{
			// 거리가 d 이하이면 큐에 추가
			if (!visited[there] && dist[here][there] <= d)
			{
				visited[there] = true;
				q.push(there);
			}
		}
	}
	// 모든 기지가 연결 되었으면 true
	return seen == n;
}

// 최적화 문제: 거리를 기반으로 이분법 탐색
double optimize()
{
	double lo = 0, hi = 1416; // 최대 거리+1
	for (int i = 0; i < 100; i++)
	{
		double mid = (lo + hi) / 2;
		// 해당 거리내에 모든 지점을 연결 가능하면
		if (decision(mid))
			hi = mid; // 더 작은 값을 찾는다
		// 연결 불가능 하면
		else
			lo = mid; // 더 큰 값을 찾는다
	}
	return hi;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		vector<pair<double, double>> g(n); // 좌표값 저장
		for (int i = 0; i < n; i++)
		{
			double x, y;
			cin >> x >> y;
			g[i] = make_pair(x, y);
		}
		dist.resize(n, vector<double>(n));
		// 거리 저장
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				// 거리 구하기
				double d = sqrt(pow(g[i].first - g[j].first, 2) + pow(g[i].second - g[j].second, 2));
				// 무방향 그래프 저장
				dist[i][j] = d;
				dist[j][i] = d;
			}
		}
		// 소수점 3번째 자리에서 반올림 하여 출력
		cout.precision(2);
		cout << fixed << optimize() << '\n';
		dist.clear();
	}
}
