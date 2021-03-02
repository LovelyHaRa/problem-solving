#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
int n, m;

// 인접 리스트에 대한 dfs 탐색
void dfs(int here)
{
	for (int i = 0; i < adj[here].size(); i++)
	{
		int k = adj[here][i];
		if (!visited[k])
		{
			visited[k] = 1;
			dfs(k);
		}
	}
}

int main(void)
{
	cin >> n >> m;
	adj.resize(n + 1, vector<int>());
	visited.resize(n + 1);
	// 인접 리스트 표현
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int cnt = 0;
	// 모든 정점에 대해 dfs를 호출한 횟수가 컴포넌트 갯수임
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << '\n';
}