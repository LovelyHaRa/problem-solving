#include<iostream>
#include<algorithm>

using namespace std;

int num[100000];
int dp[100000];

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	int res;
	res = dp[0] = num[0];
	/*
	  - 점화식
	  dp[i]=max(dp[i-1]+num[i] ,num[i])
	  이전까지의 선택된 값과 현재 값을 합한 것과 현재 값중 큰 값을 선택
	*/
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + num[i], num[i]);
		res = res < dp[i] ? dp[i] : res;
	}
	cout << res << endl;
}
