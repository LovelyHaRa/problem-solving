#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<long long> pass(n);
	long long low = 0, high = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> pass[i];
		// 1. 최대범위 저장(가장 오래 걸리는 시간 * 사람 수)
		high = max(pass[i], high);
	}
	high *= m;
	long long res = high;
	// 2. 이분 탐색
	while (low <= high)
	{
		// mid = 시간
		long long mid = (low + high) / 2;
		long long sum = 0;
		// 3. 한사람이 심사한 사람수 = (전체시간/입국담당자시간) 를 누적
		for (int i = 0; i < n; i++)
			sum += mid / pass[i];
		// 4. 누적값이 같거나 크면 최솟값 갱신 후 우측범위 줄이기
		if (sum >= m)
		{
			res = min(res, mid);
			high = mid - 1;
		}
		// 5. 그렇지 않으면 좌측범위 줄이기
		else
			low = mid + 1;		
	}
	cout << res << '\n';
}
