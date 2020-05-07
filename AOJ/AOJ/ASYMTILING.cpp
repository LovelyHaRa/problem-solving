#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> cache;
const int MOD = 1000000007;

// 타일링 경우의 수
int tiling(int width)
{
	if (width <= 1) return 1;
	int& ret = cache[width];
	if (ret != -1) return ret;
	return ret = (tiling(width - 1) + tiling(width - 2)) % MOD;
}

// 전체 경우의수 - 대칭 경우의 수 로 구하기
int asymmetric(int width)
{
	// 뺀 결과가 음수 일 수 있기 때문에 나머지를 더해 준 후 MOD 연산
	// 1. 너비가 홀수일 경우: 반쪽 타일링의 수를 구함(자연스럽게 나머지 한쪽은 대칭)
	if (width % 2 == 1)
		return (tiling(width) - tiling(width / 2) + MOD) % MOD;
	// 2. 짝수일 때는 두가지 경우가 있으므로 모두 뺴 준다
	int ret = tiling(width);
	ret = (ret - tiling(width / 2 - 1) + MOD) % MOD; // 가로 타일이 두개 있는 경우
	ret = (ret - tiling(width / 2) + MOD) % MOD; // 타일이 없는 경우
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		cache.resize(n + 1, -1);
		cout << asymmetric(n) << '\n';
		cache.clear();
	}
}