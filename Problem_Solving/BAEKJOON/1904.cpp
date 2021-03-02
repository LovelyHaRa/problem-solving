// 점화식을 이용한 DP문제

#include<iostream>

using namespace std;

int dp[1000001]; // dp 배열

int main(void)
{
	int N;	
	cin >> N;
	// 개수의 관계를 비교하여 점화식을 구성한 결과
	// dp[N]=dp[N-1]+dp[N-2]
	// (dp[N] => N자리수일 때의 구성할 수 있는 이진수 개수)
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 15746;
	}
	cout << dp[N]<<'\n';
}
