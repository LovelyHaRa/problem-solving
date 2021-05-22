#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> cache;

int tiling(int n)
{
	// 기저 사례: 1, 2는 경우의 수가 1개뿐이다.
	if (n <= 1) return 1;
	// 메모이제이션
	int& ret = cache[n];
	if (ret != -1) return ret;
	// 세로타일 1개만 쓰는 경우와 가로타일 2개를 쓰는 경우를 더함
	return ret = (tiling(n - 1) + tiling(n - 2)) % 1000000007;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		cache.resize(n + 1, -1);
		cout << tiling(n) << '\n';
		cache.clear();
	}
}
