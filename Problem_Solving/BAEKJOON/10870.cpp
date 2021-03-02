#include<iostream>

using namespace std;

int f(int n)
{
	if (!n)
		return 0;
	if (n < 3)
		return 1;
	return f(n - 1) + f(n - 2);
}

int main(void)
{
	int n;
	cin >> n;
	cout << f(n) << endl;
}