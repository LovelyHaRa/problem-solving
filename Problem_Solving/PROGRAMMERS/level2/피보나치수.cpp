#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	vector<int> dp;
	dp.push_back(0);
	dp.push_back(1);
	// 메모제이션 이용
	for (int i = 2; i <= n; i++) {
		// 계산 과정에서 각각 나머지를 구하는것과 모두 계산한 뒤 나머지를 구한값은 똑같음을 이용
		dp.push_back((dp[i - 2] % 1234567 + dp[i - 1] % 1234567) % 1234567);
	}
	int answer = dp[n];
	return answer;
}