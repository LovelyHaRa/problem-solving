#include<iostream>
#include<queue>

using namespace std;

int adj[100][100][100]; // 높이, 세로, 가로 인접 행렬
bool visited[100][100][100]; // 높이, 세로, 가로 방문여부

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, h;
	cin >> m >> n >> h;
	queue<pair<int, pair<int, int>>> q; // 높이, 세로, 가로 페어 저장
	int seq = 0, curSeq, day = 0; // 큐에 저장된 횟수, 결과일 수
	// 입력
	for (int i = h - 1; i >= 0; i--)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
			{
				cin >> adj[i][j][k];
				// 익은 토마토일 시 큐에 초기값으로 추가
				if (adj[i][j][k] == 1)
				{
					// 큐에 삽입
					q.push(make_pair(i, make_pair(j, k)));
					seq++; // 큐에 저장된 횟수 증가
				}
			}
	// 6방향 증가량
	int dx[] = { -1,0,0,1,0,0 }, dy[] = { 0,-1,1,0,0,0 }, dz[] = { 0,0,0,0,-1,1 };
	// BFS 탐색
	while (!q.empty())
	{
		curSeq = 0; // 현재 턴에서 큐에 저장된 횟수를 카운팅하기위해 초기화
		bool flag = 0; // 하나라도 안익은 토마토를 익게했는지 여부
		// 이전에 큐에 저장된 횟수만큼 큐에서 추출(하루)
		for (int i = 0; i < seq; i++)
		{
			// 큐에서 추출
			int x = q.front().second.first, y = q.front().second.second, z = q.front().first;
			q.pop();
			// 6방향 탐색
			for (int j = 0; j < 6; j++)
			{
				// 좌표 갱신
				int nx = x + dx[j], ny = y + dy[j], nz = z + dz[j];
				// 이동 가능 여부 판단
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h || visited[nz][nx][ny] || adj[nz][nx][ny])
					continue;
				curSeq++; // 큐에 저장된 횟수 증가
				flag = 1; // 토마토를 익게 했으므로 true로 변경
				visited[nz][nx][ny] = 1; // 방문여부 갱신
				q.push(make_pair(nz, make_pair(nx, ny))); // 큐에 삽입
			}
		}
		if (flag) day++; // 토마토를 익게 했으면 날짜 증가
		seq = curSeq; // 큐에 저장된 횟수 갱신
	}
	// 인접 행렬 탐색
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for(int k = 0; k < m; k++)
				// 미방문되고 안익은 토마토 발견 시
				if (!visited[i][j][k] && !adj[i][j][k])
				{
					cout << "-1\n"; // 모두 익지 못하는 상황
					return 0;
				}
	cout << day << '\n'; // 모두 익었다면 걸린 일 수 출력
}
