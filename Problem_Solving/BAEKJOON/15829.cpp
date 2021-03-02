#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	int l;
	cin >> l;
	string s;
	cin >> s;
	long long sum = 0;
	long long r = 1;
	for (int i = 0; i < l; i++)
	{
		long long k = (s[i] - 96) * r % 1234567891;
		sum = (sum + k) % 1234567891;
		r = r * 31 % 1234567891;
	}
	cout << sum << '\n';
}