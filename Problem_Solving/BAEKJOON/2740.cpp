// 수학
#include<iostream>

using namespace std;

int A[100][100], B[100][100], C[100][100];

int main(void)
{
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> A[i][j];
	}
	cin >> m >> k;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
			cin >> B[i][j];
	}
	// n*m 과 m*k의 행렬 곱셈은 n*k의 행렬이 나옴
	// 행렬 곱셈 구하듯이 그대로 하면 됨
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int h = 0; h < m; h++)
				C[i][j] += A[i][h] * B[h][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			cout << C[i][j] << ' ';
		cout << '\n';
	}
}