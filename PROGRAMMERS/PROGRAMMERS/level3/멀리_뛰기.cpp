#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
	// 규칙을 찾아보니 피보나치 수열이었다.
	long long a = 1, b = 2;
	if (n == 1) return n; // 1일 때 처리
	// n이 2가 될 때 까지 감소
	while (n-- >= 3) {
		// 피보나치 수열 계산
		long long c = (a + b) % 1234567;
		a = b;
		b = c;
	}
	return b % 1234567;
}