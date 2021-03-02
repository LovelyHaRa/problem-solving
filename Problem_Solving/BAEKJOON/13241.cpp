#include<iostream>

using namespace std;

int GCD(long long a, long long b)
{
	if (a < b) return GCD(a, b%a);
	if (b == 0) return a;
	GCD(b, a%b);
}

int main(void)
{
	long long a, b;
	cin >> a >> b;
	cout << (a*b) / GCD(a, b) << endl;
}
