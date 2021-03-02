#include<iostream>
#include<vector>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<vector<int>> cache(2, vector<int>(n, 0));
	int res;
	res = cache[0][0] = cache[1][0] = a[0];
	for (int i = 1; i < n; i++)
	{
		// 0번줄 a[i]를 포함했을 때의 연속합의 최댓값을 저장
		cache[0][i] = max(cache[0][i - 1] + a[i], a[i]);
		// 1번줄 a[i]를 포함하지 않았을 때 연속합의 최대값을 저장
		// cache[1][i-1]은 0~i-1 중 하나의 값이 포함되지 않았기 때문에 a[i]를 반드시 포함해야함
		cache[1][i] = max(cache[0][i - 1], cache[1][i - 1] + a[i]);
		res = max(res, max(cache[0][i], cache[1][i]));
	}
	cout << res << '\n';
}
