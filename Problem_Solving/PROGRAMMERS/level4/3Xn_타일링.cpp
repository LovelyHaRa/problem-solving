#include <string>
#include <vector>

using namespace std;

vector<long long> cache;
int mod = 1000000007;

int solution(int n) {
	if (n % 2) return 0;
	vector<long long> cache(n + 1);
	cache[0] = 1;
	cache[1] = 0;
	int sum = 0; // 특수한 모양 누적
	for (int i = 2; i <= n; i += 2) {
		// 기본 모양은 3개, 특수한 모양은 2개씩 만들 수 있음
		cache[i] = (3 * cache[i - 2] + 2 * sum) % mod;
		sum = (sum + cache[i - 2]) % mod;
	}
	return cache[n] % mod;
}