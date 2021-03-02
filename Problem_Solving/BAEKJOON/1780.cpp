// 분할 정복
// 쿼드트리
#include<iostream>

using namespace std;

int paper[2800][2800];
int first, second, thrid;

void nineTree(int x, int y, int length)
{
	int start = paper[x][y];
	for (int i = x; i < x + length; i++)
	{
		for (int j = y; j < y + length; j++)
		{
			if (paper[i][j] != start)
			{
				nineTree(x, y, length / 3);
				nineTree(x, y + length / 3, length / 3);
				nineTree(x, y + length / 3 * 2, length / 3);
				nineTree(x + length / 3, y, length / 3);
				nineTree(x + length / 3, y + length / 3, length / 3);
				nineTree(x + length / 3, y + length / 3 * 2, length / 3);
				nineTree(x + length / 3 * 2, y, length / 3);
				nineTree(x + length / 3 * 2, y + length / 3, length / 3);
				nineTree(x + length / 3 * 2, y + length / 3 * 2, length / 3);
				return;
			}
		}
	}
	switch (start)
	{
	case -1:
		first++;
		break;
	case 0:
		second++;
		break;
	case 1:
		thrid++;
		break;
	}
}

int main(void)
{
	int n;
	cin >> n;
	// 쿼드트리랑 풀이법 같음
	// 분할을 9개로 해주면 됨
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	}
	first = second = thrid = 0;
	nineTree(0, 0, n);
	cout << first << '\n' << second << '\n' << thrid << '\n';
}
