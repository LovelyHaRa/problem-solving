#include<iostream>
#include<algorithm>

using namespace std;

char c[100][100];
int n, m;
int res = 65;
int cnt = 0;

char white[8][9] =
{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

char black[8][9] =
{
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int whitePaint(int x, int y)
{
	cnt = 0;
	for (int i = x; i < x + 8; i++)
	{		
		for (int j = y; j < y + 8; j++)
		{
			if (c[i][j] != white[i - x][j - y])
				cnt++;
		}
	}
	return cnt;
}

int blackPaint(int x, int y)
{
	cnt = 0;
	for (int i = x; i < x + 8; i++)
	{
		for (int j = y; j < y + 8; j++)
		{
			if (c[i][j] != black[i - x][j - y])
				cnt++;
		}
	}
	return cnt;
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	int x = n - 8;
	int y = m - 8;
	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j <= y; j++)
			res = min(res, min(whitePaint(i, j), blackPaint(i, j)));
	}
	cout << res << endl;
}
