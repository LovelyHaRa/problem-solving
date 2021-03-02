#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void)
{
	int m, n;
	cin >> m >> n;
	vector<vector<int>> adj(n, vector<int>(m));
	vector<vector<int>> visited(n, vector<int>(m));
	queue<pair<int, int>> q;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	int seq = 0, curSeq, day = 0; // 전날에 큐에 추가된 횟수, 당일 큐에 추가된 횟수, 일수
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> adj[i][j];
			// 1이면 큐에 추가
			if (adj[i][j] == 1)
			{
				q.push(make_pair(i, j));
				seq++; // 큐에 추가된 횟수 증가
			}
		}
	// bfs 탐색
	while (!q.empty())
	{
		curSeq = 0;
		int flag = 0; // 인접한 토마토가 이미 익었거나 없다는 것을 파악하기 위한 플래그
		// 전날 큐에 추가된 횟수만큼 큐에서 꺼낸다
		for (int i = 0; i < seq; i++)
		{
			int x = q.front().first, y = q.front().second;
			visited[x][y] = 1;
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j], ny = y + dy[j];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && !adj[nx][ny])
				{
					curSeq++; // 당을 큐에 추가된 횟수 추가
					flag = 1; // 안익은 토마토를 발견(일수를 증가)
					adj[nx][ny] = 1;
					q.push(make_pair(nx, ny)); // 큐에 삽입
				}
			}
		}
		seq = curSeq; // 큐에 추가된 횟수 갱신
		if (flag) day++; // 안익은 토마토가 발견되면 일수를 증가
	}
	// 안익은 토마토가 있는지 확인
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && !adj[i][j])
			{
				cout << "-1\n";
				return 0;
			}
		}
	// 안익은 토마토가 없으면 일수 출력
	cout << day << '\n';
}