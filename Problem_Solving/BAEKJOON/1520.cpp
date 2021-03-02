#include<iostream>
#include<cstring>

using namespace std;

int m, n; // 행렬 길이
int map[501][501]; // 데이터
int v[501][501]; // 이미 방문한 정점인지 체크
int pos[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }; // 상하좌우 이동거리


int process(int x, int y)
{
	if (x == m && y == n) return 1; // 기저 사례
	int &res = v[x][y];
	if (res != -1) return res; //방문여부 체크
	res = 0;
	// 메모제이션
	for (int i = 0; i < 4; i++)
	{
		int dx = x + pos[i][0];
		int dy = y + pos[i][1];
		// 새로운 좌표가 맵데이터 범위 내에 존재하고 내리막이면 이동
		if (dx <= m && dy <= n && dx >= 1 && dy >= 1 && map[dx][dy] < map[x][y])
			res += process(dx, dy);
	}
	return res;
}

int main(void)
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	}
	// 방문여부 -1로 초기화
	memset(v, -1, sizeof(v));	
	cout << process(1, 1) << endl;
}