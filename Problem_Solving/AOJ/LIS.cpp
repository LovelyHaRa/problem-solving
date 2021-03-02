#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> cache;
vector<int> A;

int max(int a, int b) { return a > b ? a : b; }
int lis(int start)
{
	// 메모이제이션
	int& ret = cache[start];
	if (ret != -1) return ret;
	ret = 1; // A[start]가 존재하므로 최솟값은 무조건 1임
	// 기저 사례 처리가 필요없음.(기저 사례를 만족하면 반복문이 수행되지 않음)
	for (int i = start + 1; i < n; i++)
		if (A[start] < A[i]) ret = max(ret, lis(i) + 1); // 순증가 한다면 현재 탐색점을 바탕으로 재귀호출
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		A.resize(n);
		for (int i = 0; i < n; i++)
			cin >> A[i];
		cache.resize(n, -1);
		int res = 0;
		// 시작위치를 모두 결정해주어야 한다.
		for (int i = 0; i < n; i++)
			res = max(res, lis(i)); // 최대값 갱신
		cout << res << '\n';
		A.clear();
		cache.clear();
	}
}