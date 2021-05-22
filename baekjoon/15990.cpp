#include<iostream>
#include<vector>

using namespace std;

const int N = 100000;
const int MOD = 1000000009;

int main(void)
{	
	// 미리 답을 구해 놓는다(캐싱)
	// cache[n][k] => n의 값을 표현했을 때 마지막 수가 k인 경우의 수
	vector<vector<long long>> cache(N + 1, vector<long long>(4));
	// 1일 경우: 1 , 2일 경우: 2, 3일 경우: 1+2, 2+1, 3
	cache[1][1] = cache[2][2] = cache[3][1] = cache[3][2] = cache[3][3] = 1;
	for (int i = 4; i <= N; i++)
	{
		// 점화식
		if (i - 1 >= 0)
			cache[i][1] = (cache[i - 1][2] + cache[i - 1][3]) % MOD;
		if (i - 2 >= 0)
			cache[i][2] = (cache[i - 2][1] + cache[i - 2][3]) % MOD;
		if (i - 3 >= 0)
			cache[i][3] = (cache[i - 3][1] + cache[i - 3][2]) % MOD;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << (cache[n][1] + cache[n][2] + cache[n][3]) % MOD << '\n';
	}
}
