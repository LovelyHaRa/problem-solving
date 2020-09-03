#include<iostream>
#include<queue>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	bool visited[200][200] = { 0, }; // 좌표 방문 여부
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	// 이동 증가량
	int dr[] = { -2,-2,0,0,2,2 };
	int dc[] = { -1,1,-2,2,-1,1 };
	// 초기 큐 세팅
	queue<pair<int, int>> q;
	q.push(make_pair(r1, c1));
	visited[r1][c1] = 1;
	int moveCnt = 0; // 이동 횟수
	// BFS 탐색
	while (!q.empty())
	{
		int curSize = q.size(); // 현재 이동한 곳에서 다음 이동까지 가능한 모든 경우의 수
		while (curSize--)
		{
			// 쿠에서 추출
			int cr = q.front().first, cc = q.front().second;
			q.pop();
			// 목표지점 도착 확인
			if (cr == r2 && cc == c2)
			{
				// 출력 후 프로그램 종료
				cout << moveCnt << '\n';
				return 0;
			}
			// 좌표 이동 여부
			for (int i = 0; i < 6; i++)
			{
				int nr = cr + dr[i], nc = cc + dc[i]; // 좌표 갱신
				// 조건 확인
				if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc]) continue;
				// 이동할 수 있음을 의미
				visited[nr][nc] = 1; // 방문 체크
				q.push(make_pair(nr, nc)); // 큐에 추가
			}
		}
		moveCnt++;
	}
	cout << "-1\n"; // 목표 위치에 도달하지 못함
}