// 분할 정복
#include <iostream>
#include <vector>

using namespace std;

int n;
long long b;
vector<vector<int>> a(5, vector<int>(5));

vector<vector<int>> pow(long long b)
{
	vector<vector<int>> res(n, vector<int>(n));
	vector<vector<int>> t(n, vector<int>(n));
	// 1. 제곱수가 1일 때
	if (b == 1)
	{
		// 행렬 출력
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				t[i][j] = a[i][j] % 1000;
		}
		return t;
	}
	// 2. 제곱수가 짝수일 때
	// X^2b = x^b*x^b 이용
	else if (!(b % 2))
	{
		// b/2 일 때의 행렬 구함
		t = pow(b / 2);

		// 행렬 제곱 수행(t*t)
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
					res[i][j] += t[i][k] * t[k][j];
				res[i][j] %= 1000;
			}				
		}

		return res;
	}
	// 3. 제곱수가 홀수일 때
	// x^b = x^b-1*x 이용
	else
	{
		// b-1 일 때의 행렬 구함
		t = pow(b - 1);

		// t*a 수행
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
					res[i][j] += t[i][k] * a[k][j];
				res[i][j] %= 1000;
			}			
		}

		return res;
	}
}

int main(void)
{
	cin >> n >> b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	vector<vector<int>> res(n, vector<int>(n));

	res = pow(b);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << res[i][j] << ' ';
		cout << '\n';
	}
}