#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> A;
	A.push_back(-1987654321);
	int cnt = 0;
	while (n--)
	{
		int k;
		cin >> k;
		// 순증가 한다면 뒤에 삽입
		if (k > A.back())
		{
			A.push_back(k);
			cnt++;
		}
		else
		{
			vector<int>::iterator find = lower_bound(A.begin(), A.end(), k); // 이분 탐색으로 k보다 큰 정수의 위치 반환
			*find = k; // 바꿔치기
		}
	}
	cout << cnt;
}