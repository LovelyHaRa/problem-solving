#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> cache(1001, -1);

int tiling(int n)
{
	if (n <= 1) return 1;
	int& ret = cache[n];
	if (ret != -1) return ret;
	// 타일링이랑 비슷하지만 2*2 타일이 추가되었기 때문에 *2 해줘야 한다.
	return ret = (tiling(n - 1) + tiling(n - 2) * 2) % 10007;
}

int main(void)
{
	cin >> n;
	cout << tiling(n);
}