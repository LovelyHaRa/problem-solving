#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> dp(n + 1); // dp[n]: n일 때 최소 제곱 수 개수
	// 기저값 세팅, dp[0]=0
	dp[1] = 1;
	// 2부터 n까지 수에 대해서 최소 제곱 수 개수를 계산한다
	for (int i = 2; i <= n; i++)
	{
		int min_cnt = 5; // 최대값: 4
		// j의 제곱 수가 i 이하일 때 까지 반복
		for (int j = 1; j * j <= i; j++)
		{
			int k = i - j * j; // i에서 제곱 수 만큼 뺀다
			min_cnt = min(min_cnt, dp[k]); // 메모이제이션된 값과 비교해서 최소값을 갱신한다
		}
		dp[i] = min_cnt + 1; // 제곱 수 하나가 추가되었으므로 1을 더해준다
	}
	cout << dp[n] << '\n'; // dp[n]을 출력한다
}