#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> p(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> p[i][j];
	}
	int max = 0;
	int sum = 0;
	// 무식하게 풀기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// -
			if (j + 3 < m)
			{
				sum += p[i][j] + p[i][j + 1] + p[i][j + 2] + p[i][j + 3];
				max = max < sum ? sum : max;
				sum = 0;
			}
			// l
			if (i + 3 < n)
			{
				sum += p[i][j] + p[i + 1][j] + p[i + 2][j] + p[i + 3][j];
				max = max < sum ? sum : max;
				sum = 0;
			}
			// ㅁ
			if (i + 1 < n&&j + 1 < m)
			{
				sum += p[i][j] + p[i][j + 1] + p[i + 1][j] + p[i + 1][j + 1];
				max = max < sum ? sum : max;
				sum = 0;
			}
			if (i + 2 < n&&j + 1 < m)
			{
				// L
				sum += p[i][j] + p[i + 1][j] + p[i + 2][j] + p[i + 2][j + 1];
				max = max < sum ? sum : max;
				sum = 0;
				// └┐
				sum += p[i][j] + p[i + 1][j] + p[i + 1][j + 1] + p[i + 2][j + 1];
				max = max < sum ? sum : max;
				sum = 0;
				// Γ
				sum += p[i][j] + p[i + 1][j] + p[i + 2][j] + p[i][j + 1];
				max = max < sum ? sum : max;
				sum = 0;
				// ㅏ
				sum += p[i][j] + p[i + 1][j] + p[i + 2][j] + p[i + 1][j + 1];
				max = max < sum ? sum : max;
				sum = 0;
				// ┙
				sum += p[i][j + 1] + p[i + 1][j + 1] + p[i + 2][j] + p[i + 2][j + 1];
				max = max < sum ? sum : max;
				sum = 0;
				// ┌┘
				sum += p[i][j + 1] + p[i + 1][j + 1] + p[i + 1][j] + p[i + 2][j];
				max = max < sum ? sum : max;
				sum = 0;
				// ㄱ
				sum += p[i][j + 1] + p[i + 1][j + 1] + p[i + 2][j + 1] + p[i][j];
				max = max < sum ? sum : max;
				sum = 0;
				// ㅓ
				sum += p[i][j + 1] + p[i + 1][j + 1] + p[i + 2][j + 1] + p[i + 1][j];
				max = max < sum ? sum : max;
				sum = 0;
			}
			if (i+1<n && j+2<m)
			{
				// ㄴ
				sum += p[i][j] + p[i + 1][j] + p[i + 1][j + 1] + p[i + 1][j + 2];
				max = max < sum ? sum : max;
				sum = 0;
				// ㄱ_
				sum += p[i][j] + p[i][j + 1] + p[i + 1][j + 1] + p[i + 1][j + 2];
				max = max < sum ? sum : max;
				sum = 0;
				// ┌
				sum += p[i][j] + p[i][j + 1] + p[i][j + 2] + p[i + 1][j];
				max = max < sum ? sum : max;
				sum = 0;
				// ㅜ
				sum += p[i][j] + p[i][j + 1] + p[i][j + 2] + p[i + 1][j + 1];
				max = max < sum ? sum : max;
				sum = 0;
				// ─┐
				sum += p[i][j] + p[i][j + 1] + p[i][j + 2] + p[i + 1][j + 2];
				max = max < sum ? sum : max;
				sum = 0;
				// ─┘
				sum += p[i + 1][j] + p[i + 1][j + 1] + p[i + 1][j + 2] + p[i][j + 2];
				max = max < sum ? sum : max;
				sum = 0;
				// _┌
				sum += p[i + 1][j] + p[i + 1][j + 1] + p[i][j + 1] + p[i][j + 2];
				max = max < sum ? sum : max;
				sum = 0;
				// ㅗ
				sum += p[i + 1][j] + p[i + 1][j + 1] + p[i + 1][j + 2] + p[i][j + 1];
				max = max < sum ? sum : max;
				sum = 0;
			}
			sum = 0;
		}
	}
	cout << max;
}