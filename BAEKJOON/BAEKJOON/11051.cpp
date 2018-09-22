#include<iostream>
using namespace std;
int C[1001][1001];
int main(void)
{
	C[0][0] = C[1][0] = C[1][1] = 1;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (j == 0 || j == N) C[i][j] = 1;
			else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 10007;
		}
	}
	cout << C[N][K] << endl;
}