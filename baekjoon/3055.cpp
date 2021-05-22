#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int main(void)
{
	int r, c;
	cin >> r >> c;
	vector<string> map(r); // 지도 정보
	queue<pair<int, int>> water_pos; // 초기에 물이 차 있는 지역의 좌표
	queue<pair<int, int>> q; // 고슴도치 이동 좌표
	//  좌표 별 물이 차기까지의 시간, 좌표 별 이동 시간
	vector<vector<int>> water_map(r, vector<int>(c)), check(r, vector<int>(c));
	for (int i = 0; i < r; i++)
	{
		cin >> map[i];
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == '*') water_pos.push(make_pair(i, j)); // 물이 차 있는 지역 좌표를 큐에 저장
			else if (map[i][j] == 'S') q.push(make_pair(i, j)); // 시작 지점 큐에 저장
		}
	}
	int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }; // 상하좌우 이동 증가량
	// 물이 차는 시간을 알기 위해 BFS 탐색
	while (!water_pos.empty())
	{
		// 큐에서 추출
		int x = water_pos.front().first;
		int y = water_pos.front().second;
		water_pos.pop();
		// 상하좌우 이동
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i]; // 새로운 좌표 값
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue; // 범위 밖이면 건너뛰기
			// 물이 이동할 수 있는 곳에만 이동
			if (!water_map[nx][ny] && map[nx][ny] == '.')
			{
				water_map[nx][ny] = water_map[x][y] + 1; // 시간 증가
				water_pos.push(make_pair(nx, ny)); // 큐에 삽입
			}
		}
	}
	// 고슴도치 이동 BFS 탐색
	while (!q.empty())
	{
		// 큐에서 추출
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		// 종료조건: 도착지점에 도달 시
		if (map[x][y] == 'D')
		{
			// 출력 후 프로그램 종료
			cout << check[x][y] << '\n';
			return 0;
		}
		// 상하좌우 이동
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i]; // 새로운 좌표 값
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue; // 범위 밖이면 건너 뛰기
			// 이동 가능한 조건
			// 1. 방문하지 않은 경우
			// 2. 도착지점일 경우
			// 3. 비어있는 곳이면서 물이 아예 차오르지 않은 지역이거나 물이 차는 시간이 현재 위치 + 1 보다 크면
			if (!check[nx][ny] && (map[nx][ny] == 'D' || (map[nx][ny] == '.' && (!water_map[nx][ny] || water_map[nx][ny] > check[x][y] + 1))))
			{
				check[nx][ny] = check[x][y] + 1; // 이동 시간 계산
				q.push(make_pair(nx, ny)); // 큐에 삽입
			}		
		}
	}
	cout << "KAKTUS\n"; // 불가능한 경우 출력
}
