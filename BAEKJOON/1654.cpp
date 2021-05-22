#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int k, n;
	cin >> k >> n;
	vector<long long> cable(k);
	long long left = 1, right = 0;
	int res = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> cable[i];
		right = right < cable[i] ? cable[i] : right; // 초기 오른쪽 값 구하기
	}
	// 자를 길이 기준으로 이분 탐색
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long cnt = 0;
		// 랜선 자르기
		for (int i = 0; i < k; i++)
			cnt += cable[i] / mid;
		// n개 이상이면
		if (cnt >= n)
		{
			res = res < mid ? mid : res; // 자를 수 있는 최대 길이 갱신
			left = mid + 1; // 왼쪽 갱신
		}
		else right = mid - 1; // 오른쪽 갱신
	}
	cout << res << '\n';
}
