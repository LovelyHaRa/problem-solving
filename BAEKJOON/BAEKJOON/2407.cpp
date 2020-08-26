#include<iostream>
using namespace std;

typedef struct BigInt
{
	long long high;
	long long low;
};
const long long maxSize = 1e18;
BigInt operator+(BigInt x, BigInt y)
{
	BigInt z;
	z.high = x.high + y.high;
	if (x.low + y.low >= maxSize)
	{
		z.low = x.low + y.low - maxSize;
		z.high++;
	}
	else
		z.low = x.low + y.low;
	return z;
}

BigInt C[101][101];
int main(void)
{
	C[0][0].low = C[1][0].low = C[1][1].low = 1;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (j == 0 || j == N) C[i][j].low = 1;
			else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
		}
	}
	if (C[N][K].high != 0)
		cout << C[N][K].high;
	cout << C[N][K].low << endl;
}