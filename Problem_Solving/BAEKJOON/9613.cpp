#include<iostream>
#include<vector>

using namespace std;

// 최대공약수(유클리드 호제법)
int gcd(int a, int b)
{
	if (a > b) return gcd(a%b, b);
	if (!a) return b;
	return gcd(b%a, a);
}

int main(void)
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> k(n);
		for (auto it = k.begin(); it != k.end(); it++)
			cin >> *it;
		long long sum = 0;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
				sum += gcd(k[i], k[j]);
		}
		cout << sum << '\n';
	}
}
