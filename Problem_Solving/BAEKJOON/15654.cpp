#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	do
	{
		for (int i = 0; i < m; i++)
			cout << a[i] << ' ';
		cout << '\n';
		reverse(a.begin() + m, a.end()); // 나머지 m개 건너뛰기
	} while (next_permutation(a.begin(), a.end()));
}