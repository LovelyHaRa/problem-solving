#include <string>
#include <vector>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int dp[501][501];

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	// 1. 상단 값 dp 스택에 저장
	dp[0][1] = triangle[0][0];	
	// 2. 다음 라인부터 윗라인 왼쪽 수와 오른쪽 수 중 더했을 때 큰 값 저장
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 1; j <= i + 1; j++) {
			dp[i][j] += triangle[i][j - 1] + max(dp[i - 1][j - 1], dp[i - 1][j]);
			// 3. 마지막 라인 때 최댓값 저장
			if (i == triangle.size() - 1) {
				answer = answer < dp[i][j] ? dp[i][j] : answer;
			}
		}
	}
	return answer;
}
