#include<iostream>
#include<vector>

using namespace std;

int jump(const vector<vector<int>>& board, vector<vector<int>>& cache, int n, int y, int x)
{
	// 기저 사례: 영역을 벗어나면 뛸 수 없음
	if (y >= n || x >= n) return 0;
	// 기저 사례: 마지막 칸에 도달하면 가능한 것이므로 1 리턴
	if (y == n - 1 && x == n - 1) return 1;
	int& ref = cache[y][x]; // 참조변수
	if (ref != -1) return ref; // 캐싱되어있으면 캐싱 값 리턴
	int jumpSize = board[y][x]; // 좌표값=점프가능칸
	// 재귀탐색과 동시에 캐싱
	return ref = jump(board, cache, n, y + jumpSize, x) || jump(board, cache, n, y, x + jumpSize);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<vector<int>> cache(n, vector<int>(n, -1)); // 메모제이션 캐시
		vector<vector<int>> board(n, vector<int>(n)); // 보드
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> board[i][j];
		}
		cout << (jump(board, cache, n, 0, 0) ? "YES\n" : "NO\n");
	}
}