#include<iostream>
#include<vector>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<vector<int>> cache(2, vector<int>(n + 2, 0)), sticker(2, vector<int>(n + 2, 0));
		for (int i = 2; i < n + 2; i++)
			cin >> sticker[0][i];
		for (int i = 2; i < n + 2; i++)
			cin >> sticker[1][i];
		// cache[k][i] = k번줄에서 i번쨰 스티커를 뗄 수 있는 최대값
		// 점화식: cache[k][i]=sticker[k][i]+max(cache[!k][i-1], cache[!k][i-2])
		for (int i = 2; i < n + 2; i++)
		{
			cache[0][i] = sticker[0][i] + max(cache[1][i - 1], cache[1][i - 2]);
			cache[1][i] = sticker[1][i] + max(cache[0][i - 1], cache[0][i - 2]);
		}
		cout << max(cache[0][n + 1], cache[1][n + 1]) << '\n'; // 더 큰 값 출력
	}
}
