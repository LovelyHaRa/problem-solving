#include <string>
#include <vector>

using namespace std;

long long dp[90];

long long solution(int N) {
	long long answer = 0;
	// 피보나치 구현 문제
	dp[1] = 1;
	dp[2] = 1;
	// 점화식 N>=3, dp(N) = dp(N-2)+dp(N-1) , dp(1)=dp(2)=1;
	for (int i = 3; i <= N + 1; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	// 사각형 구성: 가로 dp(N), 세로 dp(N+1)
	answer = dp[N + 1] * 2 + dp[N] * 2;

	return answer;
}
