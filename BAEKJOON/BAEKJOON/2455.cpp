#include<iostream>

using namespace std;

int main(void)
{
	int d, u, res = 0, max = 0;
	for (int i = 0; i < 4; i++)
	{		
		cin >> d >> u;
		res = res - d + u;
		max = max < res ? res : max;
	}
	cout << max << endl;
}