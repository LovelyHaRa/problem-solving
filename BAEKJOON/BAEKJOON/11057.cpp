#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> cache;

const int mod = 10007;

// n번째 위치에 k가 올 수 있는 경우의 수 반환
int solve(int n, int k)
{
	// 기저 사례: n이 1자리일 때 경우의 수는 1개
	if (n == 1) return 1;
	// 메모이제이션
	int& ret = cache[n][k];
	if (ret != -1) return ret;
	ret = 0; // 초기세팅
	// n-1 위치에 올 수 있는 수는 현재 수보다 같거나 작아야 한다.
	// 따라서 solve(n-1, k~9)까지의 경우의 수를 모두 더한다
	for (int i = k; i <= 9; i++)
		ret = (ret + solve(n - 1, i)) % mod; // 누적합의 나머지를 저장
	return ret;
}

int main(void)
{
	int n;
	cin >> n;
	cache.resize(n + 1, vector<int>(10, -1));
	int res = 0;
	for (int i = 0; i <= 9; i++)
		res = (res + solve(n, i)) % mod; // 누적합의 나머지를 저장
	cout << res << '\n';
}