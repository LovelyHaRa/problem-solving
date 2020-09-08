#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> map; // 연구실 지도
vector<pair<int, int>> virus; // 초기 바이러스 위치
int n, m, maxArea;

// 바이러스 확산 시뮬레이션
int diffusion()
{
	vector<vector<int>> nextMap = map;
	vector<vector<bool>> checked(n, vector<bool>(m));
	// 초기 큐 생성
	queue<pair<int, int>> q;
	int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 };
	for (int i = 0; i < virus.size(); i++)
	{
		q.push(virus[i]);
		checked[virus[i].first][virus[i].second] = 1;
	}
	// BFS 탐색
	while (!q.empty())
	{
		// 큐에서 추출
		int x = q.front().first, y = q.front().second;
		q.pop();
		// 상하좌우 이동
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i]; // 다음 좌표
			// 범위 밖, 이미 방문, 벽은 건너뛰기
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || checked[nx][ny] || nextMap[nx][ny] == 1) continue;
			checked[nx][ny] = 1; // 체크
			nextMap[nx][ny] = 2; // 바이러스 확산
			// 큐에 추가
			q.push(make_pair(nx, ny));
		}
	}
	// 안전 영역 계산
	int safeArea = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			safeArea += !nextMap[i][j];
	return safeArea;
}

// 가능한 모든 벽 설치
void buildWail(int cnt)
{
	// 벽 설치 완료
	if (cnt == 3)
	{
		int area = diffusion(); // 바이러스 확산
		if (maxArea < area) maxArea = area; // 안전영역 최댓값 갱신
		return;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!map[i][j])
			{
				map[i][j] = 1;
				buildWail(cnt + 1); // DFS 탐색
				map[i][j] = 0;
			}
}

int main(void)
{
	cin >> n >> m;
	map.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2) virus.push_back(make_pair(i, j));
		}
	buildWail(0);
	cout << maxArea << '\n';
}