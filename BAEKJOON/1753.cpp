#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int V, E, K;
	cin >> V >> E >> K;
	// 정점 인접 리스트 (연결된 정점, 가중치 페어)
	vector<vector<pair<int, int>>> vertex(V + 1);
	while (E--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vertex[u].push_back({v, w});
	}
	// 정점까지의 거리의 최솟값 기반 우선순위 큐(거리의 최솟값, 정점 페어)
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int INF = 1987654320;
	// 각 정점까지의 거리의 최솟값을 저장하는 배열
	vector<int> dist(V + 1, INF);
	// 초기 값 세텅
	dist[K] = 0;		 // 출발점 거리는 0
	pq.push({0, K}); // 큐에 삽입
	// 큐에 값이 없을 때 까지 탐색
	while (!pq.empty())
	{
		// 현재 가중치, 현재 정점 추출
		int cw = pq.top().first, cv = pq.top().second;
		pq.pop();
		// 현재 정점과 연결된 정점 탐색
		for (int i = 0; i < vertex[cv].size(); i++)
		{
			// 연결된 정점 및 가중치 저장
			int nv = vertex[cv][i].first;
			int nw = vertex[cv][i].second;
			// 연결된 정점의 최소 거리 갱신
			if (dist[nv] > cw + nw)
			{
				dist[nv] = cw + nw;
				pq.push({cw + nw, nv}); // 큐에 삽입
			}
		}
	}
	// 출력
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}
}