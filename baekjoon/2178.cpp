#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<string> adj(n); // 인접 행렬 그래프
	vector<vector<int>> visited(n, vector<int>(m)); // 방문 여부
	vector<vector<int>> move(n, vector<int>(m)); // 해당 좌표까지의 이동 경로 누적합
	for (int i = 0; i < n; i++)
		cin >> adj[i];
	int dx[] = { -1,0,0,1 };
	int dy[] = { 0,-1,1,0 };
	queue<pair<int,int>> q; // bfs 탐색 큐
	// 시작 지점 큐에 삽입
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		pair<int, int> cur=q.front();
		q.pop();
		int x = cur.first, y = cur.second;
		visited[x][y] = 1; // 방문 체크
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			// 범위 내인지, 1인지, 미방문되었는지 체크
			// 큐에 대기중일 때 다른 정점에 의해 방문될 수도 있으므로, move값의 갱신 여부도 조건에 추가
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && adj[nx][ny] == '1' && !move[nx][ny])
			{
				move[nx][ny] = move[x][y] + 1; // 경로 누적
				q.push(make_pair(nx, ny)); // 큐에 정점 추가
			}
		}
	}
	cout << move[n - 1][m - 1] + 1 << '\n';
}
