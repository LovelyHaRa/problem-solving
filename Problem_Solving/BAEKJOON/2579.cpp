#include<iostream>
using namespace std;
int max(int a, int b) { return a > b ? a : b; }
int main(void)
{
	int s[300] = { 0 }, d[300] = { 0 }, n, i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> s[i];
	d[0] = s[0];
	d[1] = s[0]+s[1];
	d[2] = max(s[0] + s[2], s[1] + s[2]);
	for (i = 3; i < n; i++)
		d[i] = max(d[i - 3] + s[i - 1] + s[i], d[i - 2] + s[i]);
	cout << d[n - 1] << endl;
}