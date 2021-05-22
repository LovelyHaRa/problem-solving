#include<iostream>

using namespace std;

int main(void)
{
	int x[5];
	int min = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> x[i];
		min += x[i];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 3; j < 5; j++)
		{
			int k = x[i] + x[j] - 50;
			min = min > k ? k : min;
		}
	}
	cout << min << '\n';
}
