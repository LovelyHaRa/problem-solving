#include <string>
#include <vector>

using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	// 1. 초기값 갱신
	dp[1][1] = 1;
	// 2. 웅덩이는 -1로 초기화
	for (vector<int> i : puddles) {
		dp[i[1]][i[0]] = -1;
	}
	// 3. 탐색
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// 4. 웅덩이를 만나면 0으로 체인지
			if (dp[i][j] == -1) {
				dp[i][j] = 0;
			}
			else {
				// 5. 첫번째 줄이면 왼쪽값을 더해줌
				if (i == 1) {
					dp[i][j] += dp[i][j - 1];
				} // 6. 두번쨰 줄부터는 좌측, 상단값을 더해서 지정된 수로 나눈 나머지를 더해줌
				else {
					dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
				}
			}
		}
	}
	// 7. 그렇게 누적시킨 값을 반환
	answer = dp[n][m];
	return answer;
}