#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> k(n + 1); // k[i] = 1~i까지의 합
	// 1. k[i] 생성
	for (int i = 1; i <= n; i++) {
		k[i] = i + k[i - 1];
	}
	// i~j의 합 = (1~j의 합) - (1-i) 합임을 이용하여 해결
	// 2. k 탐색
	for (int i = 1; i <= n; i++) {
		int j = i;
		// i~j의 합이 n이면 answer 추가
		// 3. j를 늘려가면서 i~j의 합을 구함 
		while (k[j] - k[i - 1] <= n) {
			if (k[j++] - k[i - 1] == n) {
				answer++;
				break;
			}
		}
	}
	return answer;
}