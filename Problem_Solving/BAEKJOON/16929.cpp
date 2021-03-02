#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n, m;
vector<string> adj; // 게임판
pair<int, int> start; // 시작지점
int res = 0; // 사이클 생성 여부
// 상화좌우 이동 증가량
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };

// dfs 탐색 (위치(x, y), 시작지점 색깔, 방문 여부)
void dfs(int x, int y, char dot, vector<vector<int>> visited)
{
	// 상하좌우 탐색
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i]; // 새로운 x, y 좌표
		// 좌표가 게임판 영역 내인지, 해당 좌표가 시작지점과 똑같은 색일 때,
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && adj[nx][ny] == dot)
		{
			// 해당 좌표가 시작지점인 경우
			if (nx == start.first && ny == start.second)
				// 사이클 가능 조건: 시작점에서 (x, y)까지 이동 횟수가 3 이상
				if (visited[x][y] >= 3)
				{
					res = 1; // 사이클 생성됨
					return;
				}
			else
				// 방문되지 않은 정점인 경우
				if (!visited[nx][ny])
				{
					// 이전 위치에서의 이동 횟수에 1을 더한 값을 저장
					visited[nx][ny] = visited[x][y] + 1;
					// dfs 탐색
					dfs(nx, ny, dot, visited);
					// 사이클이 생성되었으면 탐색 종료
					if (res) return;
				}
		}
	}
}

int main(void)
{
	
	cin >> n >> m;
	adj.resize(n);
	for (int i = 0; i < n; i++)
		cin >> adj[i];
	// 게임판 위 모든 정점을 시작점으로 하여 dfs 탐색
	// 사이클이 생성되는 즉시 Yes 출력 후 종료
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			start = make_pair(i, j); // 시작 지점 좌표 갱신
			// dfs 탐색 시작
			dfs(i, j, adj[i][j], vector<vector<int>>(n, vector<int>(m)));
			// 사이클이 생성될 수 있으면
			if (res)
			{
				// Yes 출력
				cout << "Yes\n";
				return 0;
			}
		}
	cout << "No\n";	
}