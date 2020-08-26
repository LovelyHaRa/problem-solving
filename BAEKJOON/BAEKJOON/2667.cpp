#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// 이동 증가량
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
vector<string> adj; // 인접 행렬
vector<vector<int>> visited; // 방문 여부 인접 행렬
vector<int> res; // 단지별 번호 개수
int n, cnt; // 사각형 개수, 단지별 카운팅 변수

void dfs(int x, int y)
{
	visited[x][y] = 1; // 방문 체크
	cnt++; // 단지 카운팅
	// 4방향내에 집이 있으면 dfs 호출
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + dx[i], nexty = y + dy[i];
		if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n && !visited[nextx][nexty] && adj[nextx][nexty] == '1')
			dfs(nextx, nexty);
	}
}

int main(void)
{
	cin >> n;
	adj.resize(n);
	visited.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		cin >> adj[i];
	// 인접행렬을 탐색하면서 dfs 호출
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cnt = 0;
			if (!visited[i][j] && adj[i][j] == '1')
			{
				dfs(i, j);
				// dfs가 끝나면 단지 하나가 생성됨
				res.push_back(cnt);
			}			
		}
	}
	sort(res.begin(), res.end()); // 오름차순 정렬
	cout << res.size() << '\n'; // 단지 개수 출력
	// 단지별 카운트 출력
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << '\n';
}