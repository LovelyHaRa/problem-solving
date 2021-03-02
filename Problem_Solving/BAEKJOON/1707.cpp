#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj; // 인접 리스트
vector<int> visited; // 0: 미방문 // 1,2 // 정점을 구분하는 숫자
int n;

// DFS 탐색
void dfs(int here, int color)
{
	for (int i = 0; i < adj[here].size(); i++)
	{
		int v = adj[here][i];
		if (!visited[v])
		{
			visited[v] = color;
			dfs(v, 3 - color); // 다른 색깔로 색칠
		}
	}
}

// 그래프가 이분 그래프인지 확인
bool isBipartite()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
		{
			int v = adj[i][j];
			// 리스트중 색깔이 같은 것이 있으면 이분그래프가 아니다
			if (visited[i] == visited[v])
				return false;
		}
	}
	return true;
}

int main(void)
{
	int k;
	cin >> k;
	while (k--)
	{
		int m;
		cin >> n >> m;
		adj.resize(n + 1, vector<int>());
		visited.resize(n + 1);
		// 인접 리스트에 그래프 표현
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		// 모든 정점에 대해 DFS 탐색
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
				dfs(i, 1);
		}
		cout << (isBipartite() ? "YES\n" : "NO\n");
		adj.clear();
		visited.clear();
	}
}