#include<iostream>
#include<vector>

using namespace std;

int n, k;
vector<vector<long long>> cache(201, vector<long long>(201,-1));

// 주어진 수 k개로 n을 표현할 수 있는 경우의 수를 반환
int decomposition(int k, int n)
{
	// 기저 사례: k==1 이면 1가지 뿐이다
	if (k == 1) return 1;
	// 메모이제이션
	long long& ret = cache[k][n];
	if (ret != -1) return ret;
	ret = 0; // 초기값
	// 점화식: decomposition(k,n) = sigma(i:0~n)[decomposition(k-1,i)]
	for (int i = 0; i <= n; i++)
		ret = (ret + decomposition(k - 1, i)) % 1000000000;
	return ret;
}

int main(void)
{
	cin >> n >> k;
	cout << decomposition(k, n);
}
