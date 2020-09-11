#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int n, m;
vector<string> map; // 맵 정보
vector<vector<int>> moveableGroup; // 맵에서 이동가능한 지역들을 그룹화한 정보
vector<int> moveableCnt; // 그룹별 이동가능한 지역 개수
vector<vector<bool>> visited; // BFS 방문 여부
int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }; // 상하좌우 증가량

// BFS 탐색 후 이동가능한 지역 개수를 반환
int BFS(int startX, int startY, int groupIdx)
{
	int cnt = 1;
	// 초기 큐 생성
	queue<pair<int, int>> q;
	visited[startX][startY] = 1;
	moveableGroup[startX][startY] = groupIdx;
	q.push(make_pair(startX, startY));
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
			// 범위 밖, 이미 방문, 벽이면 건너뛰기
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || map[nx][ny] == '1') continue;
			visited[nx][ny] = 1; // 방문 체크
			moveableGroup[nx][ny] = groupIdx; // 그룹 번호 부여
			q.push(make_pair(nx, ny)); // 큐에 추가
			cnt++; // 이동 가능한 횟수 증가
		}
	}
	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	map.resize(n);
	moveableGroup.resize(n, vector<int>(m));
	visited.resize(n, vector<bool>(m));
	for (int i = 0; i < n; i++)
		cin >> map[i];
	int groupIdx = 1;
	// 1. 이동가능한 지역 그룹 번호 부여
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visited[i][j] && map[i][j] == '0')
				moveableCnt.push_back(BFS(i, j, groupIdx++));
	// 2. 벽 부수고 이동 가능한 횟수 계산
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 벽인 경우
			if (map[i][j] == '1')
			{
				vector<bool> checked(moveableCnt.size()); // 그룹 중복 확인 배열
				int cnt = 1; // 벽을 제거하므로 초기 상태는 1
				// 상하죄우 탐색
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k], ny = j + dy[k]; // 다음 좌표
					// 범위 밖이면 건너뛰기
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					// 그룹 번호 추출
					groupIdx = moveableGroup[nx][ny];
					// 벽이거나 이미 체크한 그룹이면 건너뛰기
					if (!groupIdx || checked[groupIdx - 1]) continue;
					checked[groupIdx - 1] = 1; // 체크
					cnt += moveableCnt[groupIdx - 1]; // 카운팅
				}
				cout << cnt % 10; // 10으로 나눈 나머지 출력
			}
			else cout << 0; // 아니면 0 출력
		}
		cout << '\n';
	}
}