#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adj; // 그래프 인접 리스트 표현
vector<int> check; //  0: 미방문, 1: 방문, 2: 사이클에 포함됨
vector<int> dist; // 사이클과의 거리

// 현재 정점과 이전 정점을 기반으로 dfs 탐색을 하여 사이클을 찾는다.
// -2: 사이클이 포함된 노드가 아님, -1: 리프 노드, 0이상: 사이클 시작점 노드
int dfs(int here, int prev)
{
	if (check[here]) return here; // 부모 정보 반환
	check[here] = 1; // 방문 체크
	// 연결된 정점 모두 방문
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i]; // 현재 정점 추출
		if (there == prev) continue; // 바로 전에 탐색한 노드(prev)는 건너뛰기
		int ret = dfs(there, here); // dfs 탐색
		if (ret == -2) return -2; // 사이클이 아닌 노드일 때
		// 사이클에 포함될 때
		if (ret >= 0)
		{
			check[here] = 2; // 사이클 표시
			if (ret == here) return -2; // 시작점일 경우 사이클이 아님
			return ret; // 정점 번호 반환
		}
	}
	return -1;
}

int main(void)
{
	int n;
	cin >> n;
	adj.resize(n + 1);
	check.resize(n + 1);
	dist.resize(n + 1);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		// 무방향 그래프 표현
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// dfs 탐색
	dfs(1, -1);
	// bfs 탐색으로 사이클과의 거리 계산
	queue<int> q;
	// 초기 큐 생성
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == 2)
			q.push(i);
	}
	// bfs 탐색
	while (!q.empty())
	{
		// 정점 추출
		int here = q.front();
		q.pop();
		// 연결된 정점 모두 탐색
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			if (check[there] == 2) continue; // 사이클이면 건너뜀
			check[there] = 2; // 방문 체크
			dist[there] = dist[here] + 1; // 거리 계산
			q.push(there); // 큐에 삽입
		}
	}
	// 출력
	for (int i = 1; i <= n; i++)
		cout << dist[i] << ' ';
	cout << '\n';
}
