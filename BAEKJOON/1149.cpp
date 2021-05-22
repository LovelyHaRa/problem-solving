#include<iostream>
using namespace std;
int min(int a, int b) { return a < b ? a : b; }
int main(void)
{
	int rgb[3], p[1001][3]={0}, N, res=1001;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> rgb[j];
			p[i][j] = min(p[i - 1][(j + 1) % 3], p[i - 1][(j + 2) % 3]) + rgb[j];
		}
	}
	cout << min(min(p[N][0],p[N][1]),p[N][2]) << endl;
}
