#include<iostream>

using namespace std;

const long long DIV = 1000000000; // 나누는 수

int main(void)
{
	int n; // 자릿수
	long long dp[100][10] = { 0 }, sum = 0; // 동적 계획 배열, 결과값
	cin >> n;
	/*
	길이가 N인 계단 수는 0~9중에 올 수 있는 자리수의 총합
	자릿수를 n, 끝자리를 d라고 하면
	점화식은 다음과 같다
	f(n,d)={
			f(n-1,1) (n=0)
			f(n-1,d-1)+f(n-1,d+1) (n>=1 && n<=8)
			f(n-1,8) (n=9)
			}
	*/
	// 초기 dp 세팅
	for (int i = 1; i < 10; i++)
		dp[0][i] = 1;
	// 길이가 n일때까지 점화식을 통한 계산
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = dp[i - 1][1] % DIV; // d=0
		for (int j = 1; j < 9; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] % DIV; // d>=1 && d<=8
		dp[i][9] = dp[i - 1][8] % DIV; // d=9
	}
	// 결과는 n번째 자리의 0~9번째 계단 수를 모두 더한 값
	for (int i = 0; i < 10; i++)
		sum += dp[n - 1][i];
	cout << sum % DIV << endl;
}
