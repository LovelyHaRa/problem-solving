#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n), cache(n); // 수열, 합계의 최대값을 저장하는 DP 배열
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		cache[i] = a[i]; // 초기값: a[i]와 같은 값
	}
	int res = 0; // 최대값 저장
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			// 조건 1: LIS를 만족하는지?(a[j]<a[i])
			// 조건 2: 합이 더 큰가?
			if (a[j] < a[i] && cache[i] < cache[j] + a[i])
				cache[i] = cache[j] + a[i]; // 최대값 갱신
		res = res < cache[i] ? cache[i] : res; // 구할 수 있는 모든 수열의 합 최대값 갱신
	}
	cout << res << '\n';
}