#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> psum(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> psum[i];
		psum[i] += psum[i - 1];
	}
	while (m--)
	{
		int i, j;
		cin >> i >> j;
		cout << psum[j] - psum[i - 1] << '\n';
	}
}