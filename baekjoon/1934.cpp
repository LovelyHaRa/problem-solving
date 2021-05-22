#include<iostream>

using namespace std;

int GCD(int a, int b)
{
	int max = a > b ? a : b;
	int min = a < b ? a : b;
	if (!(max % min))
		return min;
	else
		GCD(min, max%min);
}

int main(void)
{
	int t, a, b;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		cout << (a * b)/GCD(a, b) << endl;
	}
}
