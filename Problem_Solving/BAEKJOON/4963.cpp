#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj; // 인접 행렬
vector<vector<int>> visited; // 각 지점에 대한 방문 여부
int w, h;

void dfs(int x, int y)
{
	visited[x][y] = 1;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			// 영역 내의 값인지, 미방문지역인지, 섬인지 판단하고 dfs탐색
			if ((x + i) >= 0 && (x + i) < h && (y + j) >= 0 && (y + j) < w && !visited[x + i][y + j] && adj[x + i][y + j])
				dfs(x + i, y + j);
		}
	}
}

int main(void)
{
	while (1)
	{
		cin >> w >> h;
		if (!w && !h)
			break;
		adj.resize(h, vector<int>(w));
		visited.resize(h, vector<int>(w));
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> adj[i][j];
		int cnt = 0;
		// 모든 지역 탐색
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				// 방문되지 않은 곳의 dfs 탐색
				if (!visited[i][j] && adj[i][j])
				{
					dfs(i, j);
					cnt++; // dfs가 호출된 횟수가 컴포넌트의 개수
				}

			}
		}
		cout << cnt << '\n';
		adj.clear();
		visited.clear();
	}
}
