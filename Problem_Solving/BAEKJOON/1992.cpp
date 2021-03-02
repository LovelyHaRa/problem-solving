#include<iostream>
#include<cstdio>

using namespace std;

char video[70][70];

void quadTree(int x, int y, int length)
{
	char start = video[x][y];
	for (int i = x; i < x + length; i++)
	{
		for (int j = y; j < y + length; j++)
		{
			if (video[i][j] != start)
			{
				cout << '(';
				quadTree(x, y, length / 2);
				quadTree(x, y + length / 2, length / 2);
				quadTree(x + length / 2, y, length / 2);
				quadTree(x + length / 2, y + length / 2, length / 2);
				cout << ')';
				return;
			}
		}
	}
	cout << start;
}

int main(void)
{
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%s", video[i]);
	quadTree(0, 0, n);
	cout << endl;
}
