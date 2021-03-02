#include<iostream>
#include<queue>
#include<string>
#include<vector>

using namespace std;
// 벽을 부술수 있는 여부, x, y의 정보를 기반으로 이동 횟수 구하기
int moveCount[2][1000][1000];

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<string> map(n);
	for (int i = 0; i < n; i++)
		cin >> map[i];
	// 상하좌우 이동 증가량
	int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 };
	// 초기 큐 생성
	queue<pair<int, pair<int, int>>> q; // 부술 수 있는 여부, x, y의 정보를 기반으로 큐 생성
	q.push(make_pair(1, make_pair(0, 0)));
	moveCount[1][0][0] = 1;
	int res = -1;
	// BFS 탐색
	while (!q.empty())
	{
		pair<int, pair<int, int>> cur = q.front();
		int isBreakable = cur.first; // 부술수 있는 여부
		int x = cur.second.first, y = cur.second.second; // 현재 좌표
		q.pop();
		// 도착하면
		if (x == n - 1 && y == m - 1)
		{
			res = moveCount[isBreakable][x][y]; // 저장
			break;
		}
		// 상하좌우 이동
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			// 범위 확인
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			// 벽을 부술 수 있고 이동한 좌표가 벽인 경우
			if (isBreakable && map[nx][ny]=='1')
			{
				// 벽을 부수고 이동 횟수 계산
				moveCount[isBreakable - 1][nx][ny] = moveCount[isBreakable][x][y] + 1;
				// 큐에 삽입
				q.push(make_pair(isBreakable - 1, make_pair(nx, ny)));
			}
			// 이동한 좌표가 벽이 아니고 처음 방문한 경우
			else if (map[nx][ny]=='0' && !moveCount[isBreakable][nx][ny])
			{
				// 이동 횟수 계산
				moveCount[isBreakable][nx][ny] = moveCount[isBreakable][x][y] + 1;
				// 큐에 삽입
				q.push(make_pair(isBreakable, make_pair(nx, ny)));
			}
		}
	}
	cout << res << '\n';
}