#include<iostream>
#include<vector>

using namespace std;
const int N = 1000000;
const int mod = 1e9 + 9;
vector<long long> cache(N + 1, -1);

// n을 1,2,3의 합으로 나타내는 경우의 수
long long sum(int n)
{
	// 기저사례: n<=0
	if (n <= 0) return 0;
	// 메모이제이션
	long long& ret = cache[n];
	if (ret != -1) return ret;
	// 점화식
	return ret = (sum(n - 1) + sum(n - 2) + sum(n - 3)) % mod;
}

int main(void)
{
	cache[1] = 1;
	cache[2] = 2;
	cache[3] = 4;
	// 모든 경우를 미리 계산(재귀 깊이 때문에 미리 계산)
	for (int i = 4; i <= N; i++)
		sum(i);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout<<sum(n)<<'\n'; // 띄어쓰기 안해서 틀림,,,
	}
}