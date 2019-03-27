#include<iostream>

using namespace std;

int main(void)
{
	int t, n;
	long long dp[100];
	cin >> t;
	dp[0] = dp[1] = dp[2] = 1;
	dp[3] = dp[4] = 2;
	while (t--)
	{
		cin >> n;
		for (int i = 5; i < n; i++)
			dp[i] = dp[i - 1] + dp[i - 5];
		cout << dp[n - 1] << endl;
	}
}