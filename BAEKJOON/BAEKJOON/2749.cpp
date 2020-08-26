#include<iostream>
using namespace std;
const int mod = 1000000;
const int p = mod / 10 * 15;
int f[p] = { 0,1 };
int main(void)
{
	long long n;
	cin >> n;
	for (int i = 2; i < p; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		f[i] %= mod;
	}
	cout << f[n%p] << endl;
	return 0;
}