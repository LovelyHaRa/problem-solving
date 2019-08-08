#include<iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int sum, k = 1;
	do
	{
		int t = k;
		sum = t;
		while (t)
		{
			sum += t % 10;
			t /= 10;
		}
		if (sum == n)
		{
			cout << k << endl;
			return 0;
		}
	} while (n > k++);
	cout << 0 << endl;
}