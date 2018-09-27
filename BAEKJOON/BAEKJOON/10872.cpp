#include<iostream>
using namespace std;
int f(int n)
{
	if (n < 2)
		return 1;
	return n*f(n - 1);
}

int main(void)
{
	int N;
	cin >> N;
	cout << f(N);
}