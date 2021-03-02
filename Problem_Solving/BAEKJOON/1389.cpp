#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	int INF = 101;
	vector<vector<int>> adj(n + 1, vector<int>(n + 1, INF));
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x][y] = adj[y][x] = 1; // 친구임을 표시
		// 친구가 없는 사람은 없으므로 입력을 받을 때 자기 자신을 0으로 초기화 할 수 있다
		adj[x][x] = adj[y][y] = 0;
	}
	// 플로이드 와샬 알고리즘 이용
	// 중간 지점
	for (int k = 1; k <= n; k++)
		// 시작 지점
		for (int i = 1; i <= n; i++)
			// 도착 지점
			for (int j = 1; j <= n; j++)
				// 시작-중간+중간-도착 보다 시작-도착 거리가 작으면 갱신
				if (adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];
	int min_val = INF, res = 0;
	// 케빈 베이컨 구하기
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		// 더하기
		for (int j = 1; j <= n; j++)
			sum += adj[i][j];
		// 최솟값 갱신
		if (min_val > sum)
		{
			res = i;
			min_val = sum;
		}
	}
	cout << res << '\n';
}