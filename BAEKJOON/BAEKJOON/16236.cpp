#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
	int n; // 공간 크기
	cin >> n;
	vector<vector<int>> space(n, vector<int>(n)); // 공간 인접 행렬
	pair<int, int> shark_pos; // 아기 상어 위치
	// 입력
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> space[i][j];
			if (space[i][j] == 9)
			{
				shark_pos = { i,j };
				space[i][j] = 0;
			}
		}
	// 최솟값 갱신을 위한 한계값, 아기 상어 사이즈, 먹은 횟수, 총 이동거리(출력 값)
	int limit = 401, shark_size = 2, eating = 0, res = 0;
	int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }; // 상하좌우 이동 증가량
	// 물고기가 없어질 때 까지 반복
	while (1)
	{
		// 최소 거리일 떄의 좌표 값, 최소 거리
		int min_x = limit, min_y = limit, min_dist = limit;
		// 이동 거리 및 방문여부 체크
		vector<vector<int>> check(n, vector<int>(n, -1));
		// 초기 큐 생성
		queue<pair<int, int>> q;
		q.push(shark_pos); 
		check[shark_pos.first][shark_pos.second] = 0;
		// BFS 탐색
		while (!q.empty())
		{
			// 큐에서 좌표 추출
			int x = q.front().first, y = q.front().second;
			q.pop();
			// 상하좌우 이동
			for (int i = 0; i < 4; i++)
			{
				// 새로운 위치 좌표 값
				int nx = x + dx[i], ny = y + dy[i];
				// 범위 밖이거나 이미 방문 했거나 물고기가 아기 상어 크기보다 큰 경우 건너 뛰기
				if (nx < 0 || nx >= n || ny < 0 || ny >= n || check[nx][ny] != -1 || space[nx][ny]>shark_size) continue;
				check[nx][ny] = check[x][y] + 1; // 거리 갱신
				// 먹을 수 있는 경우
				if (space[nx][ny] > 0 && space[nx][ny] < shark_size)
				{
					// 거리의 최솟값 갱신
					if (min_dist > check[nx][ny])
					{
						min_dist = check[nx][ny];
						min_x = nx;
						min_y = ny;
					}
					// 거리의 최솟 값이 같다면
					else if (min_dist == check[nx][ny])
					{
						// 좌상단 위치 갱신
						if (min_x == nx)
							min_y = min_y > ny ? ny : min_y;
						else if (min_x > nx)
						{
							min_x = nx;
							min_y = ny;
						}
					}
				}
				// 큐에 좌표 값 저장
				q.push(make_pair(nx, ny));
			}
		}
		// 먹을 수 있는 물고기를 찾았다면
		if (min_x != limit)
		{
			res += check[min_x][min_y]; // 거리 누적
			// 아기 상어가 자기 크기만큼 물고기를 먹었으면
			if (shark_size == ++eating)
			{
				// 크기 증가 및 먹은 홧수 초기화
				shark_size++;
				eating = 0;
			}
			// 물고기 없애기
			space[min_x][min_y] = 0;
			// 아기 상어 위치 갱신
			shark_pos = { min_x,min_y };
		}
		else break; // 먹을 수 있는 물고기가 없으면 멈춘다
	}
	cout << res << '\n'; // 결과 출력
}