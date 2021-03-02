// DP 문제
// LIS 응용 문제
#include<iostream>
#define N 1001

using namespace std;

int main(void)
{
	int a[N];
	int dp[2][N] = { 0 };
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int count, max = 0;
	// 지난 수들 중에서 현재 위치보다 작은 수만 체크
	// 체크된 수들 중 DP 값이 가장 큰 수 + 1을 현재 위치 DP값에 저장
	for (int i = 1; i <= n; i++)
	{
		count = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				if (count < dp[0][j])
					count = dp[0][j];
			}
		}
		dp[0][i] = count + 1;
	}
	// 역순으로 위 작업 반복
	dp[1][n - 1] = 1;
	for (int i = n; i >= 1; i--)
	{
		count = 0;
		for (int j = n; j > i; j--)
		{
			if (a[i] > a[j])
			{
				if (count < dp[1][j])
					count = dp[1][j];
			}
		}
		dp[1][i] = count + 1;
	}
	// 두개의 dp배열을 더한 값의 최대값 -1 이 정답
	for (int i = 1; i <= n; i++)
	{
		int sum = dp[0][i] + dp[1][i];
		max = max < sum ? sum : max;
	}
	cout << max - 1 << '\n';
}