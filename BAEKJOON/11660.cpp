#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	// table[i][j]: (1, 1) ~ (i, j) 까지의 합
	vector<vector<int>> table(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> table[i][j];
			// 누적 합 구하기 (* 중복 계산된 부분은 한번 빼주기)
			table[i][j] += table[i][j - 1] + table[i - 1][j] - table[i - 1][j - 1];
		}
	while (m--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		// 부분 합 구하기 (* 중복 계산된 부분은 한번 더해주기)
		int res = table[x2][y2] - table[x2][y1 - 1] - table[x1 - 1][y2] + table[x1 - 1][y1 - 1];
		cout << res << '\n';
	}
}