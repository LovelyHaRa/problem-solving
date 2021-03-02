#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
bool answer = false;

void dfs(int here, int cnt)
{
	// 친구 관계가 4개가 되면 정답처리
	if (cnt == 4)
	{
		answer = true;
		return;
	}
	visited[here] = true; // 정점 방문 처리
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (!visited[there])
			dfs(there, cnt + 1);
		if (answer) return; // 정답을 찾은 경우 리턴
	}
	visited[here] = false; // 원상 복구
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	adj.resize(n, vector<int>());
	// 그래프 생성
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// 모든 정점을 시작점으로 DFS 탐색
	for (int i = 0; i < n; i++)
	{
		// 방문여부 배열 초기화
		visited.clear();
		visited.resize(n);
		dfs(i, 0);
		if (answer) break; // 정답을 찾은 경우 더이상 탐색하지 않음
	}
	cout << answer << '\n';
}
