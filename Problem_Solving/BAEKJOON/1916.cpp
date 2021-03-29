#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	// 도착지점, 버스비용 페어를 가지는 인접 리스트
	vector<vector<pair<int, int>>> vertex(n + 1);
	while (m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vertex[u].push_back({v, w});
	}
	int s, e;
	cin >> s >> e;
	// 버스비용, 탐색 정점의 페어로 구성된 최소 힙
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// 초기 세팅
	int INF = 1987654320;
	// 시작 지점 부터의 최소 거리를 저장하는 배열
	vector<int> dist(n + 1, INF);
	dist[s] = 0;		 // 시작지점 0으로 세팅
	pq.push({0, s}); // 큐에 삽입
	// 큐가 비어있을 때 까지 탐색
	while (!pq.empty())
	{
		// 현재 버스비용, 정점을 추출
		int cw = pq.top().first, cv = pq.top().second;
		pq.pop();
		// 현재 정점에 연결된 정점들을 탐색
		for (int i = 0; i < vertex[cv].size(); i++)
		{
			// 다음 정점, 버스비용 추출
			int nv = vertex[cv][i].first, nw = vertex[cv][i].second;
			// 최솟값 갱신
			if (dist[nv] > cw + nw)
			{
				dist[nv] = cw + nw;
				pq.push({cw + nw, nv}); // 큐에 삽입
			}
		}
	}
	// 도착 정점의 최솟값 출력
	cout << dist[e] << '\n';
}