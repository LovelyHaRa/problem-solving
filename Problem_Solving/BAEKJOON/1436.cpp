#include<iostream>

using namespace std;

int main(void)
{
	int n;
	int x = 666, cnt = 0;
	cin >> n;
	while (1)
	{		
		int t = x;
		int six = 0;
		while (t)
		{			
			six = ((t % 10) == 6) ? six + 1 : 0;
			t /= 10;
			if (six >= 3) break;
		}
		if (six >= 3) cnt++;
		if (n == cnt)
		{
			cout << x << endl;
			break;
		}
		x++;
	}
}