#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> cache(1001, -1);

int tiling(int n)
{
	// 기저 사례 : 1, 2는 각각 경우의 수가 1개
	if (n <= 1) return 1;
	// 메모이제이션
	int& ret = cache[n];
	if (ret != -1) return ret;
	// 세로 타일 하나를 쓰는 경우와 가로타일 두개를 쓰는 경우를 모두 더함;
	return ret = (tiling(n - 1) + tiling(n - 2)) % 10007;
}

int main(void)
{
	cin >> n;
	cout << tiling(n);
}