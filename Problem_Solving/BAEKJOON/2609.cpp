#include<iostream>

using namespace std;

int GCD(long long a, long long b)
{
	if (a < b) return GCD(a, b%a);
	if (b == 0) return a;
	return GCD(b, a%b);
}

int main(void)
{
	long long a, b;
	cin >> a >> b;
	cout << GCD(a, b) << endl;
	cout << (a*b) / GCD(a, b) << endl;
}