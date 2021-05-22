#include<iostream>
using namespace std;
int f[2][50];
int main(void)
{
	int T, N;
	cin >> T;
	for (; T > 0; T--)
	{
		cin >> N;
		f[0][0] = 1;
		f[1][1] = 1;
		for (int i = 2; i <= N; i++)
		{
			f[0][i] = f[0][i - 1] + f[0][i - 2];
			f[1][i] = f[1][i - 1] + f[1][i - 2];
		}
		cout << f[0][N] << " " << f[1][N] << endl;
	}
}
