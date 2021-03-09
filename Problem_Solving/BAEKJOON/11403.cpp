#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> adj(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> adj[i][j];

	// 플로이드-와샬 알고리즘 사용
	// 중간지점
	for (int k = 0; k < n; k++)
		// 시작지점
		for (int i = 0; i < n; i++)
			// 종료지점
			for (int j = 0; j < n; j++)
				// i, j가 중간지점을 통해 연결할 수 있으면 서로 연결
				if (adj[i][k] && adj[k][j])
					adj[i][j] = 1;

	// 갱신된 인접 리스트 출력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << adj[i][j] << ' ';
		cout << '\n';
	}
}