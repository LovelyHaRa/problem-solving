// DP 문제
// LIS 문제
#include<iostream>
#define N 1001

using namespace std;

int main(void)
{
	int a[N];
	int dp[N] = { 0 };
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int count, max = 0;
	// 지난 수들 중에서 현재 위치보다 작은 수만 체크
	// 체크된 수들 중 DP 값이 가장 큰 수 + 1을 현재 위치 DP값에 저장
	// DP의 최대값 출력
	for (int i = 1; i <= n; i++)
	{
		count = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				if (count < dp[j])
					count = dp[j];
			}
		}
		dp[i] = count + 1;
		max = max < dp[i] ? dp[i] : max;
	}
	cout << max << '\n';
}