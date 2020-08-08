#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int main(void)
{
	int m, n;
	cin >> m >> n;
	vector<string> adj(n);
	for (int i = 0; i < n; i++)
		cin >> adj[i]; // string 입력(붙어서 입력됨)
	queue<pair<int, int>> q;
	// broken[x][y] (x, y)까지 도달할 때 까지 부순 벽의 최소 개수
	vector<vector<int>> broken(n, vector<int>(m, 123456));
	// 상하좌우 이동 증가량
	int dx[] = { 1,0,-1,0 };
	int dy[] = { 0,1,0,-1 };
	// 초기 큐
	q.push(make_pair(0, 0));
	broken[0][0] = 0;
	// BFS 탐색
	while (!q.empty())
	{
		// 큐에서 추출
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		// 상하좌우 이동
		for (int i = 0; i < 4; i++)
		{
			// 이동 후 위치값
			int nx = x + dx[i];
			int ny = y + dy[i];
			// 범위 안에 속하는 지 확인
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				// 이동 한 곳에 벽이 있으면
				if (adj[nx][ny] == '1')
				{
					// 지금 까지 부순 벽의 최소 개수 갱신(다익스트라)
					// 벽이 있기 때문에 이전 위치에서 1 증가된 값과 비교
					if (broken[nx][ny] > broken[x][y] + 1)
					{
						broken[nx][ny] = broken[x][y] + 1;
						// 큐에 추가(중복으로 추가될 수도 있지만 연산량이 적으므로 무시)
						q.push(make_pair(nx, ny));
					}
				}
				// 벽이 없으면
				else
				{
					// 지금 까지 부순 벽의 최소 개수 갱신(다익스트라)
					// 벽이 없기 때문에 이전 위치값 그대로 비교
					if (broken[nx][ny] > broken[x][y])
					{
						broken[nx][ny] = broken[x][y];
						// 큐에 추가(중복으로 추가될 수도 있지만 연산량이 적으므로 무시)
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
	// 탐색 후 부순 벽의 최솟값 출력
	cout << broken[n - 1][m - 1] << '\n';
}