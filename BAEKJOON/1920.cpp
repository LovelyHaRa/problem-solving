#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end()); // 정렬
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		// 이분 탐색
		cout << binary_search(a.begin(), a.end(), k) << '\n';
	}
}
