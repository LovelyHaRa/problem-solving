#include<iostream>
#include<algorithm>

using namespace std;

char s1[1002], s2[1002]; // 문자열
int dp[1001][1001], i, j; // 메모제이션 배열, 반복문 변수

int main(void)
{
	cin >> s1+1 >> s2+1; // 인덱스를 1부터 시작
	/* LCS 문제
	  - 2차원 메모제이션 배열 생성
	  - 좌상단부터 좌측으로 비교 문자가 같으면 좌대각위의 값 +1 저장
	  - 같지 않으면 좌측,상단값중 최대값 저장
	  - 마지막 값이 LCS 길이의 값
	  - 문자를 구하기 위해서는 백트래킹 해야한다
	*/
	for (i = 1; s2[i]; i++)
	{
		for (j = 1; s1[j]; j++)
		{
			if (s2[i] == s1[j])
				dp[i][j] = dp[i - 1][j - 1] + 1; // 비교문자 같을 시
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 비교문자 다를 시
		}
	}
	cout << dp[i-1][j-1] << endl; // 인덱스를 1부터 시작했으므로 -1 한다
}
