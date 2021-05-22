#include <string>
#include <vector>

using namespace std;

vector<int> cache(60001, -1);

int tiling(int n) {
	// 기저 사례: 1, 2는 경우의 수가 1개임
	if (n <= 1) return 1;
	// 메모이제이션
	int& ret = cache[n];
	if (ret != -1) return ret;
	// 세로타일 1개를 쓰는 경우와 가로타일 2개를 쓰는 경우를 더함
	return ret = (tiling(n - 1) + tiling(n - 2)) % 1000000007;
}

int solution(int n) {
	return tiling(n);
}
