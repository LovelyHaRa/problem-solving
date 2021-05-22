#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<int>> cache;
const int MOD = 10000000;

int poly(int n, int first)
{
	// 기저 사례; n이 첫줄의 사각형 수와 같을 때
	if (n == first) return 1;
	// 메모이제이션
	int& ret = cache[n][first];
	if (ret != -1) return ret;
	// 초기화
	ret = 0;
	// 점화식 적용
	for (int second = 1; second <= n - first; second++)
	{
		int add = first + second - 1;
		add *= poly(n - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		cache.resize(n + 1, vector<int>(n + 1, -1));
		int sum = 0;
		// 첫 줄에 올 수 있는 사각형의 개수를 모두 탐색
		for (int i = 1; i <= n; i++) {
			sum += poly(n, i);
			sum %= MOD;
		}
		cout << sum << '\n';
		cache.clear();
	}
}
