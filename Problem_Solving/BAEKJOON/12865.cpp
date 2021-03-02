// DP 문제
// 냅색 문제
#include<iostream>

using namespace std;

int w[101], v[101];
int dp[101][100001];

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];
	// dp[i][j] => i번째까지 탐색했을 때 그 동안 담은 물건들의 합을 j라고 했을 때 가중치 값
	// i를 물건 개수만큼, j를 내가 들수 있는 최대 무게만큼 돌림
	// 배낭에 담지 않는 경우 : dp[i][j] = dp[i-1][j] (전에 탐색한거 그대로 갖고오면 됨)
	// 배낭에 담는 경우 : dp[i][j] = dp[i-1][j-w[i]]+v[i] (j에서 i번 째 보석의 무게를 뺀 것을 생각)
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = dp[i-1][j];
			if (j - w[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
	// 마지막 값 출력
	cout << dp[n][k] << '\n';
}
