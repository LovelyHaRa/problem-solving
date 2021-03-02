#include<iostream>
#include<vector>

using namespace std;

vector<long long> cache;

// 규칙 결과 피보나치 수열임을 알게 됨
long long f(int k)
{
	// 기저 사례
	if (k < 0) return 0;
	if (k <= 1) return k;
	// 메모이제이션
	long long& ret = cache[k];
	if (ret != -1) return ret;
	// 점화식 = f(n)=f(n-1)+f(n-2)
	return ret = f(k - 1) + f(k - 2);
}

int main(void)
{
	int n;
	cin >> n;
	cache.resize(n + 1, -1);
	cout << f(n);
}