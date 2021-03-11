#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<string> img;						// 그림 백터
vector<vector<bool>> visited; // 그림 좌표 방문 여부

void bfs(int x, int y)
{
	// 초기 큐 세팅
	queue<pair<int, int>> q;
	char color = img[x][y]; // 탐색할 구역의 색깔
	visited[x][y] = 1;
	q.push({x, y});
	int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0}; // 상하좌우 이동 증가량
	// BFS 탐색
	while (!q.empty())
	{
		// 큐에서 추출
		int cx = q.front().first, cy = q.front().second;
		q.pop();
		// 좌표 이동
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i]; // 다음 좌표
			// 범위 밖이거나 이미 방문한 경우 건너뛰기
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
				continue;
			// 같은색일 경우 큐에 삽입
			if (color == img[nx][ny])
			{
				visited[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	}
}

// 구역 개수를 반환하는 함수
int getArea()
{
	int area = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j])
			{
				area++; // bfs를 탐색할 때 마다 구역이 하나씩 증가
				bfs(i, j);
			}
	return area;
}

int main(void)
{
	cin >> n;
	img.resize(n);
	visited.resize(n, vector<bool>(n));
	for (int i = 0; i < n; i++)
		cin >> img[i];
	// 적록색약이 아닌사람이 봤을 때의 구역 수 구하기
	cout << getArea() << ' ';
	// 방문여부 초기화
	visited.clear();
	visited.resize(n, vector<bool>(n));
	// 초록을 빨강으로 변경
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (img[i][j] == 'G')
				img[i][j] = 'R';
	// 적록색약이 봣을 때의 구역 수 구하기
	cout << getArea() << '\n';
}