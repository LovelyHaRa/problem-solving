#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<pair<int, int>>> adj; // 정점, 가중치를 페어로 하는 인접 리스트
int n; // 정점 개수
int maxDist = 0; // 출력할 트리의 지름

// start로부터 최대 길이의 정점을 반환
int bfs(int start)
{
	queue<int> q;
	vector<bool> visited(n + 1); // 정점 방문 여부
	vector<int> dist(n + 1); // dist[v] start 부터 정점 v 까지의 거리
	int maxIdx = 0; // 반환할 정점
	// 초기 큐 세팅
	q.push(start);
	visited[start] = 1;
	// bfs 탐색
	while (!q.empty())
	{
		// 큐에서 추출
		int here = q.front();
		q.pop();
		// 인접 정점 모두 탐색
		for (int i = 0; i < adj[here].size(); i++)
		{
			// 정보 추출
			int v = adj[here][i].first; // 정점
			int w = adj[here][i].second; // 가중치
			// 미방문 시
			if (!visited[v])
			{
				visited[v] = 1; // 방문 체크
				dist[v] = dist[here] + w; // 가중치 누적
				// 가중치 최댓값 갱신
				if (maxDist < dist[v])
				{
					maxDist = dist[v];
					maxIdx = v;
				}
				// 큐에 정점 추가
				q.push(v);
			}
		}
	}
	// 최대 길이 정점 반환
	return maxIdx;
}

int main(void)
{
	cin >> n;
	adj.resize(n + 1);
	// 입력
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		while (1)
		{
			int nextv, w;
			cin >> nextv;
			if (nextv < 0) break; // -1 입력 처리
			cin >> w;
			adj[v].push_back(make_pair(nextv, w)); // 인접 리스트 구성
		}
	}
	// 1부터 시작하는 정점으로 bfs 한 뒤 반환되는 정점을 시작점으로
	// 다시 bfs 탐색 후 얻은 최대 거리를 구한다
	bfs(bfs(1));
	cout << maxDist << '\n';
}
