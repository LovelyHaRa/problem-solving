#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adj; // 인접 행렬
vector<vector<int>> visited; // 방문 여부
// 좌표 이동 증가량
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int n;

// dfs 탐색을 이용해 섬을 번호로 구분
void dfs(int x, int y, int num)
{
	visited[x][y] = 1; // 방문 체크
	adj[x][y] = num; // 번호 부여
	// 상하좌우 이동
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		// dfs 탐색
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && adj[nx][ny])
			dfs(nx, ny, num);
	}
}

// bfs 탐색을 이용해 특정 섬에서 다른 섬까지의 최소 거리를 구함
int bfs(int num)
{
	// 초기 큐 생성
	queue<pair<int, int>> q;
	// 특정 섬의 좌표는 모두 큐에 삽입
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if (adj[i][j] == num)
			{
				visited[i][j] = 1; // 방문 체크
				q.push(make_pair(i, j)); // 큐에 삽입
			}
	int dist = 0; // 다른 섬까지의 최소 거리
	while (!q.empty())
	{
		int curSize = q.size(); // 이번 루프에서의 큐 사이즈
		// 큐 사이즈가 0이 될때 까지 반복
		while (curSize-- > 0)
		{
			// 큐에서 추출
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			// 상하좌우 이동
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i], ny = y + dy[i];
				// 범위를 만족하면
				if (nx >= 0 && nx < n && ny >= 0 && ny < n)
				{
					int k = adj[nx][ny];
					// 다른 섬인 경우
					if (k && k != num)
						return dist; // 거리 리턴
					// 바다인 경우
					else if (!k && !visited[nx][ny])
					{
						visited[nx][ny] = 1; // 방문 체크
						q.push(make_pair(nx, ny)); // 큐에 추가
					}
				}
			}
		}
		dist++; //거리 1 증가
	}
}

int min(int a, int b) { return a < b ? a : b; }

int main(void)
{	
	// 입력
	cin >> n;
	adj.resize(n, vector<int>(n));
	visited.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> adj[i][j];
	// 섬 번호
	int num = 1;
	// 섬에 번호 부여
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j] && adj[i][j])
				dfs(i, j, num++);

	int res = 198765; // 거리의 최솟값
	// 모든 섬에 대하여 bfs 탐색
	for (int i = 1; i < num; i++)
	{
		// 방문 여부 배열 초기화
		visited.clear();
		visited.resize(n, vector<int>(n));
		// bfs 탐색 후 최솟값 갱신
		res = min(res, bfs(i));
	}

	cout << res << '\n';
}
