#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	a += b;
	c += d;
	cout << stoll(a) + stoll(c); // long long 으로 변환(최대: 10^13)
}