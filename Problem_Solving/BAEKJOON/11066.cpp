#include<iostream>
#include<algorithm>

using namespace std;

int novel[501]; // 파일의 크기
int sum[501]; // 1~k까지의 합
int dp[501][501]; // 동적 계획 배열

int main(void)
{
	int t, k;
	cin >> t;
	while (t--)
	{
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			cin >> novel[i];
			sum[i] = sum[i - 1] + novel[i]; // 합 저장
		}

		/*
		  - 점화식
		  dp[i][i]=novel[i], dp[i][i+1]=novel[i]+novel[i+1]
		  dp[i][j]=min(i<=mid<j){dp[i][j], dp[i][mid] + dp[mid+1][j] + sum[j] - sum[i-1](i부터 j까지의 부분합)}
		  - 삼중 for문 구조
		*/
		for (int r = 1; r < k; r++)
		{
			for (int i = 1; i + r <= k; i++)
			{
				int j = i + r;
				dp[i][j] = 987654321;
				
				for (int mid = i; mid < j; mid++)
					dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + sum[j] - sum[i - 1]);
			}
		}
		// 모든 페이지를 합쳐야 하므로 dp[1][k]의 값을 출력
		cout << dp[1][k] << endl;
	}
}
