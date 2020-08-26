#include <stdio.h>

void maketriangle(int, int, int);

char triangle[3072][6144];

int main(void)
{
	int n;
	int i, j;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (j = 0; j < 2 * n; j++)
		{
			if (j == 2 * n - 1)
				triangle[i][j] = '\0';
			else
				triangle[i][j] = ' ';
		}
	}

	maketriangle(n, n - 1, 0); // 삼각형 높이와 꼭대기 좌표를 인수로 하여 초기 호출한다.

	for (i = 0; i < n; i++)
	{
		printf("%s\n", triangle[i]);
	}
}

void maketriangle(int n, int x, int y)
{
	if (n == 3)
	{
		// 별을 찍는다
		triangle[y][x] = '*';
		triangle[y + 1][x - 1] = '*';
		triangle[y + 1][x + 1] = '*';
		triangle[y + 2][x - 2] = '*';
		triangle[y + 2][x - 1] = '*';
		triangle[y + 2][x] = '*';
		triangle[y + 2][x + 1] = '*';
		triangle[y + 2][x + 2] = '*';
		return;
	}
	maketriangle(n / 2, x, y); // 맨 위에 삼각형 꼭대기 좌표
	maketriangle(n / 2, x - (n / 2), y + (n / 2)); // 좌측 하단 삼각형 꼭대기 좌표
	maketriangle(n / 2, x + (n / 2), y + (n / 2)); // 우측 하단 삼각형 꼭대기 좌표

}