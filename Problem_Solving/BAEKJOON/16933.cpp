#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

// 상태를 구조화
struct State {
	int x, y, moveCnt, breakCnt; // 좌표, 이동횟수, 부순 벽의 개수
	bool isNight; // 밤인지 여부
	State(int _x, int _y, int _moveCnt, int _breakCnt, bool _isNight):
		x(_x),y(_y),moveCnt(_moveCnt), breakCnt(_breakCnt), isNight(_isNight) {}
};

bool visited[11][1000][1000]; // 부순벽의 개수, x,y 좌표를 기반으로 방문 체크

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> map(n); // 맵 정보
	for (int i = 0; i < n; i++)
		cin >> map[i];
	// 초기 큐 생성
	queue<State> q;
	q.push(State(0, 0, 1, 0, 0));
	visited[0][0][0] = 1;
	int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }; // 상하좌우 이동 증가량
	int res = -1;
	// BFS 탐색
	while (!q.empty())
	{
		// 큐에서 추출
		State cur = q.front();
		q.pop();
		int x = cur.x, y = cur.y, moveCnt = cur.moveCnt, breakCnt = cur.breakCnt;
		bool isNight = cur.isNight;
		// 도착했을 때
		if (x == n - 1 && y == m - 1)
		{
			res = moveCnt; // 이동 횟수 갱신
			break;
		}
		// 상하좌우 이동
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i]; // 좌표 갱신
			// 범위 밖이면 건너뛰기
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			// 이동한 지점이 벽이고 방문되지 않았다면
			if (breakCnt < k && map[nx][ny] == '1' && !visited[breakCnt + 1][nx][ny])
			{
				// 밤이면 이동하지 않고 이동거리를 증가 시키고 낮으로 바꾼 뒤 큐에 삽입
				if (isNight)
					q.push(State(x, y, moveCnt + 1, breakCnt, !isNight));
				// 낮이면 벽을 부수고 이동거리를 증가시키고 밤으로 바꾼 뒤 큐에 삽입
				else
				{
					visited[breakCnt + 1][nx][ny] = 1; // 방문 체크
					q.push(State(nx, ny, moveCnt + 1, breakCnt + 1, !isNight));
				}
			}
			// 이동한 지점이 벽이 아니고 방문되지 않았다면
			else if (map[nx][ny] == '0' && !visited[breakCnt][nx][ny])
			{
				visited[breakCnt][nx][ny] = 1; // 방문 체크
				// 큐에 이동거리를 증가시키고 낮밤을 스위칭한 뒤 큐에 삽입
				q.push(State(nx, ny, moveCnt + 1, breakCnt, !isNight));
			}
		}
	}
	cout << res << '\n';
}
