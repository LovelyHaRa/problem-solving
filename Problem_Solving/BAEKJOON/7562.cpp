#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int l;
		cin >> l;
		int a, b, x, y; // 현재 위치 (a, b), 목표 위치 (x, y)
		cin >> a >> b >> x >> y;
		vector<vector<int>> visited(l, vector<int>(l)); // 체스판 정점 방문 여부
		queue<pair<int, int>> q; // bfs queue
		// 초기상태: 시작지점을 큐에 삽입
		visited[a][b] = 1; // 체킹
		q.push(make_pair(a, b));
		// 나이트 이동 가능 좌표
		int dx[] = { -1,-2,-2,-1,1,2,2,1 };
		int dy[] = { -2,-1,1,2,2,1,-1,-2 };
		// 한번 이동했을 때 큐에 추가 횟수를 저장/갱신
		//moving: 이동횟수, flag: 목표지점에 도달하면 탈출하기 위한 플래그
		int seq = 1, curSeq, moving = 0, flag = 0;
		// bfs 탐색
		while (!q.empty())
		{
			curSeq = 0;
			// 이전에 큐에 추가된 횟수만큼 큐에서 추출(1번 이동할때 큐에 추가된 횟수)
			for (int i = 0; i < seq; i++)
			{
				// 큐에서 추출
				int cx = q.front().first;
				int cy = q.front().second;
				q.pop();
				// 목표지점 도달시 탈출
				if (cx == x && cy == y)
				{
					flag = 1;
					break;
				}
				// 현재 정점으로부터 나이트 이동
				for (int j = 0; j < 8; j++)
				{
					int nx = cx + dx[j], ny = cy + dy[j];
					// 체스판 영역 내이고 한번도 체킹되지 않았으면 큐에 추가
					if (nx >= 0 && nx < l && ny >= 0 && ny < l && !visited[nx][ny])
					{
						visited[nx][ny] = 1; // 체킹
						q.push(make_pair(nx, ny));
						curSeq++; // 큐에 추가된 횟수 추가
					}
				}
			}
			if (flag) break;
			seq = curSeq; // 큐에 추가된 횟수 갱신
			moving++; // 이동 횟수 증가
		}
		cout << moving << '\n'; // 이동횟수 출력
	}

}