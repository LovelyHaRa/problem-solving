#include<iostream>
#include<vector>

using namespace std;

const int N = 100000, mod = 9901;
vector<vector<int>> cache(N + 1, vector<int>(3, -1));

// n번째 줄에 k상황에 따른 경우의수
int zoo(int n, int k)
{
	// 기저사례: n==1
	if (n == 1) return 1;
	// 메모이제이션
	int& ret = cache[n][k];
	if (ret != -1) return ret;
	// 0: 현재 줄에 배치 안할 때, 1: 왼쪽에 배치할 때, 2: 오른쪽에 배치할 때
	switch (k)
	{
	case 0: return ret = (zoo(n - 1, 0) + zoo(n - 1, 1) + zoo(n - 1, 2)) % mod; // 이전 줄의 왼쪽+오른쪽+배치안하는경우
	case 1: return ret = (zoo(n - 1, 0) + zoo(n - 1, 2)) % mod; // 이전 줄의 오른쪽+배치안하는경우
	case 2: return ret = (zoo(n - 1, 0) + zoo(n - 1, 1)) % mod; // 이전 줄의 왼쪽+배치안하는경우
	}
}

int main(void)
{
	int n;
	cin >> n;
	cout << (zoo(n, 0) + zoo(n, 1) + zoo(n, 2)) % mod << '\n';
}