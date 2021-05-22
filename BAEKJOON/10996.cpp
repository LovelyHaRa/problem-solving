#include<iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int count = 0;
	int k = 0;
	while (count != n * n)
	{
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == k)
			{
				cout << '*';
				count++;
			}
			else {
				cout << ' ';
			}
		}
		cout << '\n';
		k = !k;
	}
}
