#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int abs(int a) { return a < 0 ? -a : a; }

int main(void)
{
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	// 오름차순 정렬
	sort(a.begin(), a.end());
	int res = 0;
	// 순열 완전탐색을 이용해서 모든 경우의 수를 조사한다
	do
	{
		int sum = 0;
		for (int i = 1; i < n; i++)
			sum += abs(a[i - 1] - a[i]); // 차이의 누적합 저장
		res = res < sum ? sum : res; // 최대값 갱신
	} while (next_permutation(a.begin(), a.end()));
	cout << res << '\n';
}
