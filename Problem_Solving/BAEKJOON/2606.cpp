#include<iostream>
#include<vector>

using namespace std;

vector<vector<bool>> network;
vector<bool> visited;
int n, m, cnt;

void dfs(int here)
{
	cnt++;
	visited[here] = 1;
	for (int i = 1; i <= n; i++)
		if (network[here][i] && !visited[i]) dfs(i);
}

int main(void)
{
	cin >> n >> m;
	network.resize(n + 1, vector<bool>(n + 1));
	visited.resize(n + 1);
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		network[x][y] = network[y][x] = 1;
	}
	dfs(1); // 1번과 연결된 네트워크 DFS 탐색
	cout << cnt - 1 << '\n'; // 1번은 제외
}
