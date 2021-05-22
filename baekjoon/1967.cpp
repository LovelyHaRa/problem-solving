#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<pair<int, int>>> adj; // 연결된 정점, 가중치를 페어로 하는 연결 리스트
int n; // 노드 개수
int maxDist; // 출력할 최대 길이

// start 노드를 시작으로 BFS 수행 뒤 시작점으로 부터 최대 길이의 노드를 반환
int bfs(int start)
{
	queue<int> q;
	vector<bool> visited(n + 1); // 방문 여부
	vector<int> dist(n + 1); // dist[n]: 시작 노드 부터 n까지의 거리
	int maxIdx = 0; // 반환할 최대 길이의 노드
	// 초기 큐 생성
	q.push(start);
	visited[start] = 1;
	// BFS 수행
	while (!q.empty())
	{
		// 큐에서 추출
		int here = q.front();
		q.pop();
		// 연결된 정점 모두 탐색
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first; // 노드
			int weight = adj[here][i].second; // 가중치
			// 미방문 시
			if (!visited[there])
			{
				visited[there] = 1; // 방문 체크
				dist[there] = dist[here] + weight; // 거리 누적
				// 거리의 최댓값 갱신
				if (maxDist < dist[there])
				{
					maxDist = dist[there];
					maxIdx = there; // 노드 갱신
				}
				// 큐에 추가
				q.push(there);
			}
		}
	}
	return maxIdx; // 최대 거리 노드 반환
}

int main(void)
{
	cin >> n;
	adj.resize(n + 1);
	// 인접 리스트 구성
	for (int i = 0; i < n-1; i++)
	{
		int r, c, w;
		cin >> r >> c >> w;
		adj[r].push_back(make_pair(c, w));
		adj[c].push_back(make_pair(r, w));
	}
	// 1부터 시작해서 BFS 수행 후 가장 긴 노드의 번호로 다시 BFS 수행
	bfs(bfs(1));
	cout << maxDist << '\n';
}
