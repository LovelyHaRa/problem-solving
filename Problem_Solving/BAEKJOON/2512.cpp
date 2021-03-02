#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// 이분탐색 문제
int main(void)
{
	int n, m;
	cin >> n;
	vector<int> budget(n);
	int low = 0, high = 0; // 이분탐색의 양 끝점
	// 1. 예산 중 최대값을 high에 저장
	for (int i = 0; i < n; i++)
	{
		cin >> budget[i];
		high = max(high, budget[i]);
	}
	cin >> m;
	int res = 0;
	// 2. 이분 탐색
	while (low <= high)
	{
		// 3. 중간값 저장
		int mid = (low + high) / 2;
		// 4. 예산 합계 저장
		int sum = 0;
		for (int i = 0; i < n; i++)
			// 중간값(현재 분배된 예산)과 현재 예산 중 최소값 누적
			sum += min(budget[i], mid);
		// 5. 합계가 총 예산보다 작으면 왼쪽값 증가 및 중간값 저장
		if (sum <= m)
		{
			res = max(mid, res); // 중간값의 최대값을 저장하기 위함
			low = mid + 1;
		}
		// 6. 총 예산을 초과하면 오른쪽 값 감소
		else
			high = mid - 1;
	}
	cout << res << '\n';
}