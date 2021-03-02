#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

bool visited[11][1000][1000]; // 부순 벽의 개수, x, y 정보를 기반으로 방문 여부 확인
queue <pair<pair<int, int>, pair<int, int>>> q; // x,y 페어, 이동거리, 부순 벽의 개수 페어 큐

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> map(n); // 맵 정보
	for (int i = 0; i < n; i++)
		cin >> map[i];
	// 초기 큐 세팅
	q.push(make_pair(make_pair(0, 0), make_pair(1,0)));
	visited[0][0][0] = 1; // 방문 체크
	int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }; // 상하좌우 이동 증가량
	int res = -1; // 최소 이동 거리
	// BFS 탐색
	while (!q.empty())
	{
		// 큐에서 추출
		pair<pair<int, int>, pair<int, int>> cur = q.front();
		q.pop();
		int x = cur.first.first, y = cur.first.second; // 좌표
		int move = cur.second.first; // 지금까지의 이동 거리
		int breakWall = cur.second.second; // 지금까지의 벽 부순 횟수
		// 끝에 도달하면
		if (x == n - 1 && y == m - 1)
		{
			res = move; // 결과 갱신
			break; // 탐색 종료
		}
		// 상하좌우 이동
		for (int i = 0; i < 4; i++)
		{
			// 다음 좌표
			int nx = x + dx[i], ny = y + dy[i];
			// 범위 밖이거나 이미 방문했다면 건너뛰기
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[breakWall][nx][ny]) continue;
			// 벽부수고 이동 가능할 때
			if (breakWall < k && map[nx][ny] == '1')
			{
				visited[breakWall + 1][nx][ny] = 1; // 벽 부수고 방문 체크
				// 큐에 삽입
				q.push(make_pair(make_pair(nx, ny), make_pair(move + 1, breakWall + 1)));
			}
			// 이동 가능한 지점이면
			else if (map[nx][ny] == '0')
			{
				visited[breakWall][nx][ny] = 1; // 방문 체크
				// 큐에 삽입
				q.push(make_pair(make_pair(nx, ny), make_pair(move + 1, breakWall)));
			}
		}
	}
	cout << res << '\n';
}
