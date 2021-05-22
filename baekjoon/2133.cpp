#include<iostream>
#include<vector>

using namespace std;

vector<int> cache;

// 3*n 직사각형에 타일을 채울 수 있는 경우의 수
int tiling(int n)
{
	// 기저사례: 홀수는 타잍을 채울 수 없다
	if (n % 2) return 0;
	// 기저사례: n==0 -> 1
	if (n == 0) return 1;
	// 기저사례 : n==2일 때 경우의 수는 3
	if (n == 2) return 3;
	// 메모이제이션
	int& ret = cache[n];
	if (ret != -1) return ret;
	// tiling(n-2)*3의 경우의수
	ret = 3 * tiling(n - 2);
	// 특수한 모양을 추가(n==4부터 2개씩 생김)
	for (int i = 0; i <= n - 4; i += 2)
		ret += 2 * tiling(i);
	return ret;
}

int main(void)
{
	int n;
	cin >> n;
	cache.resize(n + 1, -1);
	cout << tiling(n) << '\n';
}
