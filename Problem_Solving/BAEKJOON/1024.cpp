#include<iostream>
using namespace std;

int main(void)
{
	int N, L, t, x = -1;
	cin >> N >> L;
	/* 등차수열 이용
	   N = x+(x+1)+...*(x+(L-1))
	       Lx+(1+2+,,,+L-1)
		   Lx+t
	   x = (N - t) / L
	*/
	for (int i = L; i <= 100; i++)
	{
		t = (i - 1)*i / 2;
		if ((N - t) % i == 0 && (N - t) / i >= 0)
		{
			x = (N - t) / i;
			L = i;
			break;
		}
	}
	if (x < 0)
		cout << x;
	else
	{
		for (int i = 0; i < L; i++)
			cout << x + i << ' ';
	}
	cout << endl;
}