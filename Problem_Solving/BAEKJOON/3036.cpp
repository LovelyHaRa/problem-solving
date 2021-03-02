#include<iostream>

using namespace std;

/* 최대 공약수 */
int GCD(int a, int b)
{
	if (a < b) return GCD(a, b%a);
	if (b == 0) return a;
	GCD(b, a%b);
}

int main(void)
{
	int n, i;
	int r[100];
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> r[i];
	/*
	  1. i : 1 ~ n-1 
	     첫번째 링과 i번째 링의 최대 공약수를 구한다.
	     2. 각각을 최대공약수로 나눈 것을 '/'로 구분하여 출력한다.
	*/
	for (i = 1; i < n; i++)
	{
		int gcd = GCD(r[0], r[i]);
		cout << r[0] / gcd << "/" << r[i] / gcd << endl;
	}
}
