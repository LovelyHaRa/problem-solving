#include <cstdio>

int main(void)
{
	int n;
	int house[17][17] = {0};
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &house[i][j]);

	// 3차원 DP 배열, 행,열,[가로, 세로, 대각선]
	int dp[17][17][3] = {0};
	dp[1][2][0] = 1; // (1, 2)는 가로 파이프가 놓여진 경우
	// 행 탐색
	for (int i = 1; i <= n; i++)
	{
		// 열은 3부터 탐색하면 된다
		for (int j = 3; j <= n; j++)
		{
			// 벽인 경우 건너뛰기(0)
			if (house[i][j])
				continue;

			// 가로 파이프 경우의 수
			if (house[i][j - 1])
				dp[i][j][0] = 0; // 왼쪽이 벽인 경우 현재 위치에서 가로로 놓을 수 없다
			else
				dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2]; // 왼쪽의 가로+대각선 경우의 수

			// 세로 파이프 경우의 수
			if (house[i - 1][j])
				dp[i][j][1] = 0; // 위쪽이 벽인 경우 현재 위치에서 세로로 놓을 수 없다
			else
				dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2]; // 위쪽 세로+대각선 경우의 수

			//대각 파이프 경우의 수
			if (house[i][j - 1] || house[i - 1][j])
				dp[i][j][2] = 0; // 왼쪽 또는 위쪽 하나라도 벽이면 대각으로 놓을 수 없다
			else
				dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2]; // 좌상단 가로+셀+대각선 경우의 수
		}
	}
	// DP 최종값의 모든 값을 더한다
	printf("%d\n", dp[n][n][0] + dp[n][n][1] + dp[n][n][2]);
}