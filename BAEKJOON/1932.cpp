#include<iostream>
using namespace std;
int max(int a, int b) { return a > b ? a : b; }
int main(void)
{
	int t[500][501] = { 0 }, n, res = 0;
	cin >> n >> t[0][1];
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= i+1; j++)
		{
			cin >> t[i][j];
			t[i][j] += max(t[i - 1][j - 1], t[i - 1][j]);
			if (i == n - 1)	res < t[i][j] ? res = t[i][j] : res;
		}
	}
	cout << res << endl;
}
