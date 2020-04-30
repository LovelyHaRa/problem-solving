#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(const vector<int> &h, int left, int right)
{
	// 기저 사례: 범위가 1이면 막대 높이를 리턴
	if (left == right) return h[left];
	// 구간 분할
	int mid = (left + right) / 2;
	// 각개 격파
	int ret = max(solve(h, left, mid), solve(h, mid + 1, right));
	// 구간 3: 두 부분에 모두 걸치는 사각형 중 가장 큰 값을 찾는다.
	int low = mid, high = mid + 1; // 초기 세팅
	int height = min(h[low], h[high]); // 최소 높이
	ret = max(ret, height * 2); // 넓이의 최대값 갱신
	// 사각형이 모두 포함 될 때 까지 반복
	while (left < low || high < right)
	{
		// 오른쪽이 더 큰 경우 or 왼쪽 탐색이 끝난 경우
		if (high < right && (low == left || h[low - 1] < h[high + 1]))
		{
			high++; // 오른쪽 사각형을 취함
			height = min(height, h[high]); // 높이 갱신
		}
		// 그렇지 않은 경우
		else
		{
			low--; // 왼쪽 사각형을 취함
			height = min(height, h[low]); // 높이 갱신
		}
		// 넓이의 최대값 갱신
		ret = max(ret, (high - low + 1)*height);
	}
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<int> h(n);
		for (int i = 0; i < n; i++)
			cin >> h[i];
		cout << solve(h, 0, n - 1)<<'\n';
	}
}